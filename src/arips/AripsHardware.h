/*
 * AripsHardware.h
 *
 *  Created on: Apr 7, 2018
 *      Author: jgdo
 */

#ifndef ARIPS_ARIPSHARDWARE_H_
#define ARIPS_ARIPSHARDWARE_H_

#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float32.h>

#include <utl/Timer.h>

namespace arips {

class AripsHardware {
public:
    AripsHardware();

public:
    tf::TransformBroadcaster broadcaster;

    long long currentDrivenDistLeft = 0, currentDrivenDistRight = 0;
    double currentPosX = 0, currentPosY = 0, currentAngle = 0;

    SysTickTimerHandle mCheckOdometryTimer;
    SysTickTimerHandle mRequestOdometryTimer;

    ros::Time lastTime;

    nav_msgs::Odometry odom_msg;
    ros::Publisher odom_pub;

    ros::Subscriber<geometry_msgs::Twist, AripsHardware> mCmdVelSub;

    ros::Subscriber<std_msgs::Float32, AripsHardware> mKinectTiltSub;

    void cmdVelCB(const geometry_msgs::Twist& msg);

    void requestOdometryTF();

    void checkSendOdometryTF();

    void kinectTiltCb(const std_msgs::Float32& msg);
};

} /* namespace arips */

#endif /* ARIPS_ARIPSHARDWARE_H_ */
