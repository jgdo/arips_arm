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

static constexpr double ENCODER_FACTOR = 0.000863937;

static constexpr double ARIPS_WHEEL_DIST = 0.325; // TODO

#define M_TWOPI     6.28318530717958647692  /* 2*pi */

namespace arips {

AripsHardware::AripsHardware() :
        lastTime(ros::nh.now()),
        odom_pub("/odom", &odom_msg),
        mCmdVelSub("/cmd_vel", &AripsHardware::cmdVelCB, this)
{
    broadcaster.init(ros::nh);

    ros::nh.advertise(odom_pub);

    ros::nh.subscribe(mCmdVelSub);

    timer = SysTickTimer::createTimer(50, [&]() {
        this->sendOdometryTF();
    });
}

void AripsHardware::sendOdometryTF() {
    static bool first_time = true;

        if (first_time) {
            int err = hw::actuator::md25Motors.resetEncoder();
            if (err) {
                // std::cout << "Error resetting md25 distance: " << err << std::endl;
                return;
            }

            first_time = false;
        }

        auto nowTime = ros::nh.now();

        // read encoder
        long dCountL, dCountR;
        int err = hw::actuator::md25Motors.readDistance(&dCountL, &dCountR);
        if (err) {
            // std::cout << "Error reading md25 distance: " << err << std::endl;
            return;
        }

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

        // publish TF
        static geometry_msgs::TransformStamped t;

        t.header.frame_id = "/odom";
        t.header.stamp = nowTime;
        t.child_frame_id = "/base_link";

        t.transform.translation.x = currentPosX;
        t.transform.translation.y = currentPosY;

        t.transform.rotation = tf::createQuaternionFromRPY(0, 0, currentAngle);
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

} /* namespace arips */

