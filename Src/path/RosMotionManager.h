/*
 * RosMotionManager.h
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#ifndef PATH_ROSMOTIONMANAGER_H_
#define PATH_ROSMOTIONMANAGER_H_

#include "MotionManager.h"

#include <arips_arm_msgs/MotionCommand.h>
#include <arips_arm_msgs/MotionState.h>
#include <arips_arm_msgs/TrajectoryBufferCommand.h>

namespace path {

class RosMotionManager {
public:
	RosMotionManager(ctrl::Controller<Eigen::Vector2f>* controller, hw::Actuator* actuator, JointStateObserver* jso);
	
	void onControlTick();
	
	
	
private:
	MotionManager mMotionManager;
	ros::Subscriber<arips_arm_msgs::MotionCommand, RosMotionManager> mMotionCmdSub;
	ros::Subscriber<arips_arm_msgs::TrajectoryBufferCommand, RosMotionManager> mTrajBuffSub;
	
	arips_arm_msgs::MotionState mMotionStateMsg;
	ros::Publisher mMotionStatePub;
	
	void onMotionCommandCb(const arips_arm_msgs::MotionCommand& msg);
	
	void onTrajectoryBuffCb(const arips_arm_msgs::TrajectoryBufferCommand& msg);
};

} /* namespace path */

#endif /* PATH_ROSMOTIONMANAGER_H_ */
