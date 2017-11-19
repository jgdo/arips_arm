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
	mMotionCmdSub ("movement_goal", &RosMotionManager::onMotionCommandCb, this),
	mTrajBuffSub("motion_command", &RosMotionManager::onTrajectoryBuffCb, this),
	mMotionStatePub("motion_state", &mMotionStateMsg) {
	
	ros::nh.subscribe(mMotionCmdSub);
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

void RosMotionManager::onMotionCommandCb(const arips_arm_msgs::MotionCommand& msg) {
	using arips_arm_msgs::MotionCommand;
	
	if(msg.command == MotionCommand::CMD_SINGLE_TARGET) {
		mMotionManager.setNewSingleGoal(msg.st_position);
	} else if(msg.command == MotionCommand::CMD_START_TRAJECTORY) {
		mMotionManager.startFollowingTrajectory();
	} else if(msg.command == MotionCommand::CMD_STOP) {
		mMotionManager.stop();
	} else if(msg.command == MotionCommand::CMD_RELEASE) {
		mMotionManager.release();
	}
}

void RosMotionManager::onTrajectoryBuffCb(const arips_arm_msgs::TrajectoryBufferCommand& msg) {
}


} /* namespace path */

