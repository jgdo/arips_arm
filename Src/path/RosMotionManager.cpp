/*
 * RosMotionManager.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#include <path/RosMotionManager.h>


namespace path {

RosMotionManager::RosMotionManager(ctrl::Controller<Eigen::Vector2f>* controller, hw::Actuator* actuator, JointStateObserver* jso):
  mMotionManager(controller, actuator, jso),
	mSingleGoalSub ("movement_goal", &RosMotionManager::onSingleGoalCb, this),
	mControlStatePub("control_state", &mJointStatesMsg) {
	
	ros::nh.subscribe(mSingleGoalSub);
	ros::nh.advertise(mControlStatePub);
}

void RosMotionManager::onControlTick() {
	mJointStatesMsg.stamp = ros::Time::now();
	mJointStatesMsg.state[0] = mMotionManager.onControlTick();
  
	mControlStatePub.publish(&mJointStatesMsg);
}

void RosMotionManager::onSingleGoalCb(const arips_arm_msgs::joint_setpoint& msg) {
	mMotionManager.setNewSingleGoal(msg.position);
	
	
}

} /* namespace path */
