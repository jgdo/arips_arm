/*
 * MotionManager.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#include <path/MotionManager.h>

#include <hw/ControllerHardware.h>

using namespace robot::ArmConfig;

namespace path {

MotionManager::MotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm) :
		mJointController(controller), mArmHardware(arm) {
}

MotionManager::~MotionManager() {
	
}

void MotionManager::startFollowingTrajectory() {
	mCurrentState = TRAJECTORY;
	mControlCycleCount = 0;
	mPathStartTimeMs = hw::clock::getTimeMs();
}

void MotionManager::stop() {
	mCurrentState = BREAK;
	mControlCycleCount = 0;
	mArmHardware->breakMotors();
}

void MotionManager::release() {
	mCurrentState = IDLE;
	mControlCycleCount = 0;
	mArmHardware->releaseMotors();
}

void MotionManager::enterRawMode() {
	mCurrentState = RAW_MOTORS;
	mRawJointPowers.fill(0);
	mArmHardware->setRawMotorPowers(mRawJointPowers);
}

void path::MotionManager::enterDirectJointsMode() {
	mCurrentState = DIRECT_JOINTS;
	mRawJointPowers.fill(0);
	mArmHardware->setJointPowers(mRawJointPowers);
}

void path::MotionManager::setRawMotorPowers(const robot::JointPowers& powers) {
	if (mCurrentState == RAW_MOTORS) {
		mRawJointPowers = powers;
		mArmHardware->setJointPowers(mRawJointPowers);
	}
}

void MotionManager::onControlTick(JointStatesMsg& jointStates) {
	mArmHardware->readJointStates();
	const robot::JointStates& lastJointStates = mArmHardware->getJointStates();
	
	// float dtStart = (hw::clock::getTimeMs() - mPathStartTimeMs) * 0.001F;
	
	for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
		jointStates.at(i).position = lastJointStates.at(i).motionState[0];
		jointStates.at(i).velocity = lastJointStates.at(i).motionState[1];
	}
	
	robot::JointMotionStates controlInput, controlSetpoint;
	
	for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
		controlInput.at(i) = lastJointStates.at(i).motionState;
	}
	
	switch (mCurrentState) {
	case IDLE: // motors are turned off
		mArmHardware->releaseMotors();
		break;
		
	case BREAK: // motors are short-cut
		mArmHardware->breakMotors();
		break;
		
	case RAW_MOTORS:
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			jointStates.at(i).torque = 0;
			jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
			jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
		}
		break;
		
	case DIRECT_JOINTS:
			// set powers without checking since raw mode
			mArmHardware->setJointPowers(mRawJointPowers);
			for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
				jointStates.at(i).torque = mRawJointPowers.at(i);
				jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
				jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
			}
			break;
		
	case HOLD: { // motors should hold position
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			controlSetpoint.at(i) = Vec2f::Zero();
		}
		
		robot::JointPowers outputs = mJointController->computeControl(controlInput, controlSetpoint);
		
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
			jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
		}
		
		checkAndSetPWM(jointStates, outputs);
	}
		break;
		
	case TRAJECTORY: {
		TrajectoryPathBuffer::PointState ps = mTrajectoryPathBuffer.getNextSetpoint(&controlSetpoint);
		if (ps == TrajectoryPathBuffer::VALID) {
			mControlCycleCount++;
		} else if (ps == TrajectoryPathBuffer::EMPTY) {
			// if trajectory buffer is empty, hold position
			for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
				controlSetpoint.at(i) = Vec2f(lastJointStates.at(i).motionState[0], 0);
			}
		} else if (ps == TrajectoryPathBuffer::FINISHED) {
			// if trajectory finished, hold position
			for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
				controlSetpoint.at(i) = Vec2f(lastJointStates.at(i).motionState[0], 0);
			}
			mCurrentState = BREAK;
		}
		
		robot::JointPowers outputs = mJointController->computeControl(controlInput, controlSetpoint);
		
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			jointStates.at(i).setpoint_pos = controlSetpoint.at(i)[0];
			jointStates.at(i).setpoint_vel = controlSetpoint.at(i)[1];
		}
		
		checkAndSetPWM(jointStates, outputs);
		break;
	}
	}
}

void MotionManager::checkAndSetPWM(JointStatesMsg& states, robot::JointPowers& powers) {
	mArmHardware->setJointPowers(powers);
	(void)states;
	// TODO check error state
	//for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
	//	states.at(i).pwm = powers.at(i);
	//}
}

} /* namespace path */
