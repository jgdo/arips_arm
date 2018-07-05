/*
 * RosMotionManager.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#include <path/RosMotionManager.h>

using namespace robot::ArmConfig;

namespace path {

static_assert(sizeof(arips_arm_msgs::MotionState::jointStates)/sizeof(arips_arm_msgs::JointState) == NUM_JOINTS,
        "Declared number of joints is different than in message");

static_assert(sizeof(arips_arm_msgs::RawMotorCommand::raw_motor_power)/sizeof(float) == NUM_JOINTS,
        "Declared number of joints is different than in message");

static_assert(sizeof(arips_arm_msgs::TrajectoryPoint::goals)/sizeof(arips_arm_msgs::JointGoal) == NUM_JOINTS,
        "Declared number of joints is different than in message");

RosMotionManager::RosMotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm) :
		mMotionManager(controller, arm), mMotionCmdSub("motion_command", &RosMotionManager::onMotionCommandCb, this), mTrajBuffSub(
				"traj_buffer_command", &RosMotionManager::onTrajectoryBuffCb, this), mRawMotorSub("raw_motor_command",
				&RosMotionManager::onRawMotorCommandCb, this), mMotionStatePub("motion_state", &mMotionStateMsg) {
	
	ros::nh.advertise(mMotionStatePub);
	ros::nh.subscribe(mMotionCmdSub);
	ros::nh.subscribe(mTrajBuffSub);
	ros::nh.subscribe(mRawMotorSub);
}

inline static uint32_t stateToRosMode(MotionManager::State state) {
	switch (state) {
	case MotionManager::IDLE:
		return arips_arm_msgs::MotionState::M_IDLE;
	case MotionManager::BREAK:
		return arips_arm_msgs::MotionState::M_BREAK;
	case MotionManager::HOLD:
		return arips_arm_msgs::MotionState::M_HOLD;
	case MotionManager::RAW_MOTORS:
		return arips_arm_msgs::MotionState::M_RAW_MOTORS;
	case MotionManager::DIRECT_JOINTS:
		return arips_arm_msgs::MotionState::M_DIRECT_JOINTS;
	case MotionManager::DIRECT_CONTROLLER:
		return arips_arm_msgs::MotionState::M_DIRECT_CONTROLLER;
	case MotionManager::TRAJECTORY:
		return arips_arm_msgs::MotionState::M_TRAJECTORY;
	default:
		return arips_arm_msgs::MotionState::M_IDLE;
	}
}

void RosMotionManager::onControlTick() {
    uint32_t start = hw::clock::getMsTick();

	mMotionStateMsg.stamp = ros::nh.now();
	mMotionStateMsg.mode = stateToRosMode(mMotionManager.getState());

	// TODO: call directly
	MotionManager::JointStatesMsg jsm;
	// std::copy(std::begin(mMotionStateMsg.jointStates), std::end(mMotionStateMsg.jointStates), std::begin(jsm));
	mMotionManager.onControlTick(jsm);
	std::copy(std::begin(jsm), std::end(jsm), std::begin(mMotionStateMsg.jointStates));

	mMotionStateMsg.trajState.bufferCapacity = TrajectoryPathBuffer::TRAJECTORY_BUFFER_CAPACITY;
	mMotionStateMsg.trajState.controlCycleCount = mMotionManager.getControlCycleCount();
	mMotionStateMsg.trajState.numPointsInBuffer = mMotionManager.getTrajectoryBuffer().getCurrentBufferSize();
	

	uint32_t dt = hw::clock::getMsTick() - start;
	mMotionStateMsg.controlLoopTime = dt / 1000.0f;

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
	} else if (msg.command == MotionCommand::CMD_DIRECT_CONTROLLER) {
		mMotionManager.enterDirectControllerMode();
	}
}

void RosMotionManager::onTrajectoryBuffCb(const arips_arm_msgs::TrajectoryBufferCommand& msg) {
	TrajectoryPathBuffer& buf = mMotionManager.getTrajectoryBuffer();
	if (msg.start_index > mMotionManager.getControlCycleCount()) {
		return; // error: skipped points
	} else {
		if (msg.start_index == 0) {
			buf.newTrajectory(msg.size);
		}
		
		int skip = mMotionManager.getControlCycleCount() - msg.start_index;

		// TODO .size()
		for (size_t i = skip; i < std::min<size_t>(msg.size, sizeof(msg.traj_points)/sizeof(*msg.traj_points)); i++) {
			// TODO .at(i)
			if (!buf.setTrajectoryPoint(i - skip, msg.traj_points[i])) {
				break; // buffer is full
			}
		}
	}
}

void RosMotionManager::onRawMotorCommandCb(const arips_arm_msgs::RawMotorCommand& msg) {
	// TODO call directly
	robot::JointPowers pw;
	std::copy(std::begin(msg.raw_motor_power), std::end(msg.raw_motor_power), std::begin(pw));
	mMotionManager.setRawMotorPowers(pw);
}

} /* namespace path */

