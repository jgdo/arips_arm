/*
 * ros.h
 *
 *  Created on: Mar 11, 2018
 *      Author: jgdo
 */

#ifndef ROSUTIL_ROS_H_
#define ROSUTIL_ROS_H_

#include <ros/node_handle.h>
#include <rosutil/RobotRosHardware.h>

namespace ros {
extern NodeHandle_<::rosutl::RobotRosHardware, 25, 25, 2048, 512> nh;
}


#endif /* ROSUTIL_ROS_H_ */
