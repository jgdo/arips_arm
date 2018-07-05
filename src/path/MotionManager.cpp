/*
 * MotionManager.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#include <path/MotionManager.h>

#include <hw/hw.h>

using namespace robot::ArmConfig;

namespace path {

MotionManager::MotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm) :
		mJointController(controller), mArmHardware(arm){
    for(auto& v: mControlSetpoint) {
        v = Vec2f(0,0);
    }
}

MotionManager::~MotionManager() {
	
}

void MotionManager::startFollowingTrajectory() {
	mCurrentState = TRAJECTORY;
	mControlCycleCount = 0;
	mPathStartTimeMs = hw::clock::getMsTick();
}

void MotionManager::stop() {
	mCurrentState = BREAK;
	mControlCycleCount = 0;
	mArmHardware->breakMotors();
	mJointController->reset();
}

void MotionManager::release() {
	mCurrentState = IDLE;
	mControlCycleCount = 0;
	mArmHardware->releaseMotors();
	mJointController->reset();
}

void MotionManager::enterRawMode() {
	mCurrentState = RAW_MOTORS;
	mRawJointPowers.fill(0);
	mArmHardware->setRawMotorPowers(mRawJointPowers);
	mJointController->reset();
}

void path::MotionManager::enterDirectJointsMode() {
	mCurrentState = DIRECT_JOINTS;
	mRawJointPowers.fill(0);
	mArmHardware->setJointPowers(mRawJointPowers);
}

void path::MotionManager::setRawMotorPowers(const robot::JointPowers& powers) {
	if (mCurrentState == RAW_MOTORS) {
		mRawJointPowers = powers;
		mArmHardware->setRawMotorPowers(mRawJointPowers);
	} else if(mCurrentState == DIRECT_JOINTS || mCurrentState == DIRECT_CONTROLLER) {
		mRawJointPowers = powers;
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
	
	robot::JointMotionStates controlInput;
	
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
			jointStates.at(i).torque = mRawJointPowers.at(i);
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
		    mControlSetpoint.at(i) = Vec2f::Zero();
		}
		
		robot::JointPowers outputs = mJointController->computeControl(controlInput, mControlSetpoint);
		
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
			jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
		}
		
		checkAndSetPWM(jointStates, outputs);
	}
		break;
		
	case TRAJECTORY: {
		TrajectoryPathBuffer::PointState ps = mTrajectoryPathBuffer.getNextSetpoint(&mControlSetpoint);
		if (ps == TrajectoryPathBuffer::VALID) {
			mControlCycleCount++;
		} else if (ps == TrajectoryPathBuffer::EMPTY) {
			// if trajectory buffer is empty, hold position
			for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			    mControlSetpoint.at(i) = Vec2f(lastJointStates.at(i).motionState[0], 0);
			}
		} else if (ps == TrajectoryPathBuffer::FINISHED) {
		    mRelaseTrajectoryTicks = TRAJECTORY_FINISHED_RELEASE_TICKS;
			// if trajectory finished, hold position for TRAJECTORY_FINISHED_RELEASE_TICKS

			for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			    mRawJointPowers.at(i) = mControlSetpoint.at(i)[0];
			    // controlSetpoint.at(i) = Vec2f(lastJointStates.at(i).motionState[0], 0);
			}

		    // keep last mControlSetpoint
			mCurrentState = DIRECT_CONTROLLER;
		}
		
		robot::JointPowers outputs = mJointController->computeControl(controlInput, mControlSetpoint);
		
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			jointStates.at(i).setpoint_pos = mControlSetpoint.at(i)[0];
			jointStates.at(i).setpoint_vel = mControlSetpoint.at(i)[1];
		}
		
		checkAndSetPWM(jointStates, outputs);
	}
		break;
		
	case DIRECT_CONTROLLER:
	{
	    if(mRelaseTrajectoryTicks > 0) {
	        mRelaseTrajectoryTicks--;
	    } else if(mRelaseTrajectoryTicks == 0) {
	        mRelaseTrajectoryTicks = -1;
	        mArmHardware->breakMotors();
	        mCurrentState = BREAK;
	        break;
	    }

		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
		    mControlSetpoint.at(i) = Vec2f(mRawJointPowers.at(i), 0);
		}
		
		robot::JointPowers outputs = mJointController->computeControl(controlInput, mControlSetpoint);
		
		for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			jointStates.at(i).setpoint_pos = mControlSetpoint.at(i)[0];
			jointStates.at(i).setpoint_vel = mControlSetpoint.at(i)[1];
		}
		checkAndSetPWM(jointStates, outputs);
	}
		break;
	}
}

void MotionManager::checkAndSetPWM(JointStatesMsg& states, robot::JointPowers& powers) {
	mArmHardware->setJointPowers(powers);
	(void)states;
	// TODO check error state
	for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
		states.at(i).torque = powers.at(i);
	}
}

} /* namespace path */

void path::MotionManager::enterDirectControllerMode() {
	mCurrentState = DIRECT_CONTROLLER;
	
	for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
		mRawJointPowers.at(i) = mArmHardware->getJointStates().at(i).motionState[0];
	}
	
	mArmHardware->breakMotors();
}
