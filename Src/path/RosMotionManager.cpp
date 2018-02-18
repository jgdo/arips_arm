/*
 * RosMotionManager.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#include <path/RosMotionManager.h>

using namespace robot::ArmConfig;

namespace path {

RosMotionManager::RosMotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm) :
		mMotionManager(controller, arm), 
		mMotionCmdSub("motion_command", &RosMotionManager::onMotionCommandCb, this), 
		mTrajBuffSub("traj_buffer_command", &RosMotionManager::onTrajectoryBuffCb, this), 
		mRawMotorSub("raw_motor_command", &RosMotionManager::onRawMotorCommandCb, this),
		mMotionStatePub("motion_state", &mMotionStateMsg) 
{
	
	ros::nh.advertise(mMotionStatePub);
	ros::nh.subscribe(mMotionCmdSub);
	ros::nh.subscribe(mTrajBuffSub);
	ros::nh.subscribe(mRawMotorSub);
}

void RosMotionManager::onControlTick() {
	mMotionStateMsg.stamp = ros::Time::now();
	mMotionStateMsg.mode = mMotionManager.getState();
	mMotionManager.onControlTick(mMotionStateMsg.jointStates);
	mMotionStateMsg.trajState.bufferCapacity = TrajectoryPathBuffer::TRAJECTORY_BUFFER_CAPACITY;
	mMotionStateMsg.trajState.controlCycleCount = mMotionManager.getControlCycleCount();
	mMotionStateMsg.trajState.numPointsInBuffer = mMotionManager.getTrajectoryBuffer().getCurrentBufferSize();
	
	mMotionStatePub.publish(&mMotionStateMsg);
}

void RosMotionManager::onMotionCommandCb(const arips_arm_msgs::MotionCommand& msg) {
	using arips_arm_msgs::MotionCommand;
	
	if (msg.command == MotionCommand::CMD_RAW_MOTORS) {
		mMotionManager.enterRawMode();
	} else if (msg.command == MotionCommand::CMD_START_TRAJECTORY) {
		mMotionManager.startFollowingTrajectory();
	} else if (msg.command == MotionCommand::CMD_BREAK) {
		mMotionManager.stop();
	} else if (msg.command == MotionCommand::CMD_RELEASE) {
		mMotionManager.release();
	}
}

void RosMotionManager::onTrajectoryBuffCb(const arips_arm_msgs::TrajectoryBufferCommand& msg) {
	TrajectoryPathBuffer& buf = mMotionManager.getTrajectoryBuffer();
	if (msg.start_index > mMotionManager.getControlCycleCount()) {
		return; // error: skipped points
	} else {
		size_t start_index = 0;
		
		if (msg.start_index == 0) {
			start_index = 0;
			buf.newTrajectory(msg.size);
		} else {
			start_index = mMotionManager.getControlCycleCount() - msg.start_index;
		}
		
		for (size_t i = start_index; i < std::min<size_t>(msg.size, msg.traj_points.size()); i++) {
			if (!buf.addTrajectoryPoint(msg.traj_points.at(i))) {
				break; // buffer is full
			}
		}
	}
}

void RosMotionManager::onRawMotorCommandCb(const arips_arm_msgs::RawMotorCommand& msg) {
	mMotionManager.setRawMotorPowers(msg.raw_motor_power);
}

} /* namespace path */

