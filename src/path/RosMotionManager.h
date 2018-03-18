/*
 * RosMotionManager.h
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#ifndef PATH_ROSMOTIONMANAGER_H_
#define PATH_ROSMOTIONMANAGER_H_

#include "MotionManager.h"

#include <ros.h>

#include <arips_arm_msgs/MotionCommand.h>
#include <arips_arm_msgs/MotionState.h>
#include <arips_arm_msgs/TrajectoryBufferCommand.h>
#include <arips_arm_msgs/RawMotorCommand.h>

namespace path {

class RosMotionManager {
public:
	RosMotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm);
	
	void onControlTick();
	
private:
	MotionManager mMotionManager;
	ros::Subscriber<arips_arm_msgs::MotionCommand, RosMotionManager> mMotionCmdSub;
	ros::Subscriber<arips_arm_msgs::TrajectoryBufferCommand, RosMotionManager> mTrajBuffSub;
	ros::Subscriber<arips_arm_msgs::RawMotorCommand, RosMotionManager> mRawMotorSub;
	
	arips_arm_msgs::MotionState mMotionStateMsg;
	ros::Publisher mMotionStatePub;
	
	void onMotionCommandCb(const arips_arm_msgs::MotionCommand& msg);
	
	void onTrajectoryBuffCb(const arips_arm_msgs::TrajectoryBufferCommand& msg);
	
	void onRawMotorCommandCb(const arips_arm_msgs::RawMotorCommand& msg);
};

} /* namespace path */

#endif /* PATH_ROSMOTIONMANAGER_H_ */
