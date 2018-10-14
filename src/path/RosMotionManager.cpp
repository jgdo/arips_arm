/*
 * RosMotionManager.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#include <path/RosMotionManager.h>

using namespace robot::ArmConfig;

namespace path {

static_assert(sizeof(arips_arm_msgs::MotionState::jointStates)/sizeof(arips_arm_msgs::JointState) == NUM_ALL_JOINTS,
        "Declared number of joints is different than in message");

static_assert(sizeof(arips_arm_msgs::RawMotorCommand::raw_motor_power)/sizeof(float) == NUM_ALL_JOINTS,
        "Declared number of joints is different than in message");

static_assert(sizeof(arips_arm_msgs::TrajectoryPoint::goals)/sizeof(arips_arm_msgs::JointGoal) == NUM_ARM_JOINTS,
        "Declared number of joints is different than in message");

RosMotionManager::RosMotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm) :
		mMotionManager(controller, arm), mMotionCmdSub("motion_command", &RosMotionManager::onMotionCommandCb, this), mTrajBuffSub(
				"traj_buffer_command", &RosMotionManager::onTrajectoryBuffCb, this), mRawMotorSub("raw_motor_command",
				&RosMotionManager::onRawMotorCommandCb, this)
, mGripperGoalSub("gripper_raw_goal", &RosMotionManager::onGripperGoalCb, this)
, mMotionStatePub("motion_state", &mMotionStateMsg) {
	
	ros::nh.advertise(mMotionStatePub);
	ros::nh.subscribe(mMotionCmdSub);
	ros::nh.subscribe(mTrajBuffSub);
	ros::nh.subscribe(mRawMotorSub);
	ros::nh.subscribe(mGripperGoalSub);
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

void RosMotionManager::onObserveTick() {
    mMotionManager.onObserveTick();
}


void RosMotionManager::onControlTick() {
    uint32_t start = hw::clock::getMsTick();

	mMotionStateMsg.stamp = ros::nh.now();

	// TODO: call directly
	MotionManager::JointStatesMsgAll jsm;
	// std::copy(std::begin(mMotionStateMsg.jointStates), std::end(mMotionStateMsg.jointStates), std::begin(jsm));
	mMotionManager.onControlTick(jsm);
	std::copy(std::begin(jsm), std::end(jsm), std::begin(mMotionStateMsg.jointStates));

	mMotionStateMsg.trajState.bufferCapacity = TrajectoryPathBuffer::TRAJECTORY_BUFFER_CAPACITY;
	mMotionStateMsg.trajState.controlCycleCount = mMotionManager.getTrajectoryBuffer().getLastTrajectoryIndex();
	mMotionStateMsg.trajState.numPointsInBuffer = mMotionManager.getTrajectoryBuffer().getCurrentBufferSize();

	uint32_t dt = hw::clock::getMsTick() - start;
	mMotionStateMsg.controlLoopTime = dt / 1000.0f;

	mMotionStateMsg.mode = stateToRosMode(mMotionManager.getState());

	static int counter;

	if((++counter & 3) == 0) {
	    counter = 0;
	    mMotionStatePub.publish(&mMotionStateMsg);
	}
}

void RosMotionManager::onMotionCommandCb(const arips_arm_msgs::MotionCommand& msg) {
	using arips_arm_msgs::MotionCommand;
	
	if (msg.command == MotionCommand::CMD_RAW_MOTORS) {
		mMotionManager.enterRawMode();
	} else if (msg.command == MotionCommand::CMD_START_TRAJECTORY) {
		mMotionManager.enterFollowingTrajectory();
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
	/*if (msg.start_index > mMotionManager.getControlCycleCount()) {
		return; // error: skipped points
	} else */
	{
		if (msg.start_index == 0) {
		    mMotionManager.resetTrajectory(msg.size);
		}
		
		int passedIndex = buf.getLastTrajectoryIndex();

		int startInMsg = passedIndex > msg.start_index? passedIndex - msg.start_index : 0;
		int startInBuf = passedIndex < msg.start_index? msg.start_index - passedIndex : 0;

		// TODO .size()
		size_t msgIndex, bufIndex;
		for (msgIndex = startInMsg, bufIndex = startInBuf;
		        msgIndex < std::min<size_t>(msg.size, sizeof(msg.traj_points)/sizeof(*msg.traj_points))
		        && bufIndex < TrajectoryPathBuffer::TRAJECTORY_BUFFER_CAPACITY-1;
		            msgIndex++, bufIndex++) {
			// TODO .at(i)
			if (!buf.setTrajectoryPoint(bufIndex, msg.traj_points[msgIndex])) {
				break; // buffer is full
			}
		}
	}
}

void RosMotionManager::onRawMotorCommandCb(const arips_arm_msgs::RawMotorCommand& msg) {
	// TODO call directly
	robot::JointPowersAll pw;
	std::copy(std::begin(msg.raw_motor_power), std::end(msg.raw_motor_power), std::begin(pw));
	mMotionManager.setRawMotorPowers(pw);
}

void RosMotionManager::onGripperGoalCb(const std_msgs::Float32& msg) {
    mMotionManager.setGripperGoal(msg.data);
}

} /* namespace path */
