/*
 * AripsHardware.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: jgdo
 */
#include <arips/AripsHardware.h>

#include <hw/hw.h>

#include <rosutil/ros.h>

#include <tf/tf.h>

#include <algorithm>

static constexpr double ENCODER_FACTOR = 0.000863937;

static constexpr double ARIPS_WHEEL_DIST = 0.325; // TODO

#define M_TWOPI     6.28318530717958647692  /* 2*pi */

namespace arips {

AripsHardware::AripsHardware() :
        lastTime(ros::nh.now()), odom_pub("/odom", &odom_msg),
        mCmdVelSub("/cmd_vel", &AripsHardware::cmdVelCB, this),
        mKinectTiltSub("/kinect_tilt_deg", &AripsHardware::kinectTiltCb, this)
{
    broadcaster.init(ros::nh);

    ros::nh.advertise(odom_pub);

    ros::nh.subscribe(mCmdVelSub);
    ros::nh.subscribe(mKinectTiltSub);

    mCheckOdometryTimer = SysTickTimer::createTimer(1, [&]() {
        this->checkSendOdometryTF();
    });

    mRequestOdometryTimer = SysTickTimer::createTimer(20, [&]() {
        this->requestOdometryTF();
    });

    hw::servo::servoPin9->setDegrees(kinectAngle2Raw(currentKinectAngle));
}

void AripsHardware::requestOdometryTF() {
    static bool first_time = true;

    if (first_time) {
        int err = hw::actuator::md25Motors.resetEncoder();
        if (err < 0) {
            // std::cout << "Error resetting md25 distance: " << err << std::endl;
            return;
        }

        first_time = false;
    }

    hw::actuator::md25Motors.requestDistance();
}

void AripsHardware::checkSendOdometryTF() {
    // read encoder
    long dCountL, dCountR;
    int err = hw::actuator::md25Motors.tryReadDistance(&dCountL, &dCountR);
    if (err < 0) {
        // std::cout << "Error reading md25 distance: " << err << std::endl;
        return;
    }

    auto nowTime = ros::nh.now();

    long diffL = (dCountL - currentDrivenDistLeft);
    long diffR = (dCountR - currentDrivenDistRight);

    // update position
    double currentSpeed = 0, currentAngleSpeed = 0;
    if (diffL || diffR) {
        // http://www-home.fh-konstanz.de/~bittel/roboMSI/Vorlesung/04_Lokalisierung.pdf
        double theta = currentAngle;

        // delta in meter
        double fl = diffL * ENCODER_FACTOR, fr = diffR * ENCODER_FACTOR;

        double d = (fl + fr) / 2;
        double alpha = (fr - fl) / ARIPS_WHEEL_DIST;

        ros::Duration dt(nowTime.sec, nowTime.nsec);
        dt -= ros::Duration(lastTime.sec, lastTime.nsec);

        currentSpeed = d / dt.toSec();
        currentAngleSpeed = alpha / dt.toSec();

        double x = currentPosX + d * cos(theta + alpha / 2); // neue posX
        double y = currentPosY + d * sin(theta + alpha / 2); // neue posY

        currentDrivenDistLeft += diffL;
        currentDrivenDistRight += diffR;
        // currentDriveDist += (diffL + diffR) / 2;

        currentPosX = x;
        currentPosY = y;
        currentAngle += alpha;
        if (currentAngle >= M_TWOPI * 2)
            currentAngle -= M_TWOPI * 2;
        if (currentAngle < 0)
            currentAngle += M_TWOPI * 2;
    }

    lastTime = nowTime;

    static geometry_msgs::TransformStamped t;

    // publish odom tf
    t.header.frame_id = "/odom";
    t.header.stamp = nowTime;
    t.child_frame_id = "/arips_base";

    t.transform.translation.x = currentPosX;
    t.transform.translation.y = currentPosY;
    t.transform.translation.z = 0;

    t.transform.rotation = tf::createQuaternionFromRPY(0, 0, currentAngle);
    broadcaster.sendTransform(t);

    // publish kinect tf
    t.header.frame_id = "/arips_base";
    t.header.stamp = nowTime;
    t.child_frame_id = "/kinect_base";

    t.transform.translation.x = -0.125;
    t.transform.translation.y = 0;
    t.transform.translation.z = 0.72;

    t.transform.rotation = tf::createQuaternionFromRPY(0, currentKinectAngle * 3.14159265358979323846f / 180.0f, 0);
    broadcaster.sendTransform(t);

    // Publish Odometry
    odom_msg.header.stamp = nowTime;
    odom_msg.header.frame_id = "/odom";
    odom_msg.child_frame_id = "/base_link";

    odom_msg.pose.pose.position.x = currentPosX;
    odom_msg.pose.pose.position.y = currentPosY;
    odom_msg.pose.pose.position.z = 0.0;
    odom_msg.pose.pose.orientation = tf::createQuaternionFromRPY(0, 0, currentAngle);

    odom_msg.twist.twist.linear.x = currentSpeed;
    odom_msg.twist.twist.angular.z = currentAngleSpeed;

    for (int i = 0; i < 36; i++)
        odom_msg.pose.covariance[i] = 0;

    odom_msg.pose.covariance[0] = 0.01;
    odom_msg.pose.covariance[7] = 0.01;
    odom_msg.pose.covariance[14] = 99999;
    odom_msg.pose.covariance[21] = 99999;
    odom_msg.pose.covariance[28] = 99999;
    odom_msg.pose.covariance[35] = 0.01;

    for (int i = 0; i < 36; i++)
        odom_msg.twist.covariance[i] = odom_msg.pose.covariance[i];

    odom_pub.publish(&odom_msg);
}

void AripsHardware::cmdVelCB(const geometry_msgs::Twist& msg) {
    float x = msg.linear.x;
    float z = msg.angular.z * ARIPS_WHEEL_DIST / 2.0f;

    float left = (x - z);
    float right = (x + z);

    // ros::nh.loginfo("Setting motor speed.");

    hw::actuator::md25Motors.setSpeedLeftRight(left, right);
}

void AripsHardware::kinectTiltCb(const std_msgs::Float32& msg) {
currentKinectAngle = std::clamp(msg.data, -30.0f, 40.0f);
    hw::servo::servoPin9->setDegrees(kinectAngle2Raw(currentKinectAngle));
}

static constexpr size_t angleTableSize = 13;

static constexpr float rawAngleTable[angleTableSize][2] = {
    {0 ,  0.543435133025 },
    {5 ,  4.00577747242},
    {10 ,  7.43929270944},
    {15 ,  10.7974821673},
    {20 ,  14.1353404642},
    {25 ,  17.8730522187},
    {30 ,  21.1051702216},
    {35 ,  24.4142841826},
    {40 ,  27.4900813837},
    {45 ,  30.3007132009},
    {50 ,  33.0127021257},
    {55 ,  35.3792224288},
    {60 ,  37.1425467344}
};

float AripsHardware::kinectAngle2Raw(float angle) const {

   size_t idx = 0;
   for(idx = 0; idx < angleTableSize-2; idx++) {
       if(angle < rawAngleTable[idx+1][1])
       break;
   }

   float alpha = (angle - rawAngleTable[idx][1])/(rawAngleTable[idx+1][1] - rawAngleTable[idx][1]);
   return 90.0f + rawAngleTable[idx][0] * (1.0f - alpha) + rawAngleTable[idx+1][0] * alpha;
}

} /* namespace arips */

