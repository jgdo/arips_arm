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
	mMotionStatePub("motion_state", &mMotionStateMsg) {
	
	ros::nh.subscribe(mSingleGoalSub);
	ros::nh.advertise(mMotionStatePub);
}

void RosMotionManager::onControlTick() {
	mMotionStateMsg.stamp = ros::Time::now();
	mMotionStateMsg.mode = mMotionManager.getState();
	mMotionStateMsg.jointStates[0] = mMotionManager.onControlTick();
	mMotionStateMsg.trajState.bufferCapacity = TrajectoryPathBuffer::TRAJECTORY_BUFFER_CAPACITY;
	mMotionStateMsg.trajState.controlCycleCount = mMotionManager.getControlCycleCount();
	mMotionStateMsg.trajState.numPointsInBuffer = mMotionManager.getTrajectoryBuffer().getCurrentBufferSize();
	
	mMotionStatePub.publish(&mMotionStateMsg);
}

void RosMotionManager::onSingleGoalCb(const arips_arm_msgs::joint_setpoint& msg) {
	mMotionManager.setNewSingleGoal(msg.position);
	
	
}

} /* namespace path */
