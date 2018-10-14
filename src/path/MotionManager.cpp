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

void MotionManager::resetTrajectory(size_t trajSize) {
    mTrajectoryStartTime_ms = hw::clock::getMsTick();
    mTrajectoryPathBuffer.newTrajectory(trajSize);
}

void MotionManager::enterFollowingTrajectory() {
    if(mCurrentState != TRAJECTORY && mCurrentState != DIRECT_CONTROLLER) {
        mRawJointPowers.at(GRIPPER_INDEX) = mArmHardware->getJointStates().at(GRIPPER_INDEX).motionState[0];
    }

    if(mCurrentState != TRAJECTORY) {
        mCurrentState = TRAJECTORY;

        mTrajectoryStartTime_ms = hw::clock::getMsTick();

        for (size_t i = 0; i < mRawJointPowers.size(); i++) {
            mControlSetpoint.at(i) = Vec2f(mArmHardware->getJointStates().at(i).motionState[0], 0);
        }
    }
}

void MotionManager::stop() {
	mCurrentState = BREAK;
	mArmHardware->breakMotors();
	mJointController->reset();
}

void MotionManager::release() {
	mCurrentState = IDLE;
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

void MotionManager::setRawMotorPowers(const robot::JointPowersAll& powers) {
	if (mCurrentState == RAW_MOTORS) {
		mRawJointPowers = powers;
		mArmHardware->setRawMotorPowers(mRawJointPowers);
	} else if(mCurrentState == DIRECT_JOINTS || mCurrentState == DIRECT_CONTROLLER) {
		mRawJointPowers = powers;
	}
}

void MotionManager::setGripperGoal(float goal) {
    if(mCurrentState != TRAJECTORY && mCurrentState != DIRECT_CONTROLLER) {
        enterDirectControllerMode();
    }

    mRawJointPowers.at(GRIPPER_INDEX) = goal;
}

void MotionManager::enterDirectControllerMode() {
    mCurrentState = DIRECT_CONTROLLER;

    for (size_t i = 0; i < mRawJointPowers.size(); i++) {
        mRawJointPowers.at(i) = mArmHardware->getJointStates().at(i).motionState[0];
    }

    mArmHardware->breakMotors();
}

void MotionManager::onObserveTick() {
    robot::JointPowersAll lastTorque;
   for (size_t i = 0; i < lastTorque.size(); i++) {
       lastTorque.at(i) = 0;
   }
   mArmHardware->readJointStates(lastTorque);
}

void MotionManager::onControlTick(JointStatesMsgAll& jointStates) {
	const robot::JointStatesAll& lastJointStates = mArmHardware->getJointStates();

	// float dtStart = (hw::clock::getTimeMs() - mPathStartTimeMs) * 0.001F;
	
	for (size_t i = 0; i < jointStates.size(); i++) {
		jointStates.at(i).position = lastJointStates.at(i).motionState[0];
		jointStates.at(i).velocity = lastJointStates.at(i).motionState[1];
	}
	
	robot::JointMotionStatesAll controlInput;
	static_assert(jointStates.size() == controlInput.size(), "Must have equal size.");
	
	for (size_t i = 0; i < controlInput.size(); i++) {
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
		for (size_t i = 0; i < jointStates.size(); i++) {
			jointStates.at(i).torque = mRawJointPowers.at(i);
			jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
			jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
		}
		break;
		
	case DIRECT_JOINTS:
			// set powers without checking since raw mode
			mArmHardware->setJointPowers(mRawJointPowers);
			for (size_t i = 0; i < jointStates.size(); i++) {
				jointStates.at(i).torque = mRawJointPowers.at(i);
				jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
				jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
			}
			break;
		
	case HOLD: { // motors should hold position
		for (size_t i = 0; i < jointStates.size(); i++) {
		    mControlSetpoint.at(i) = Vec2f::Zero();
		}
		
		robot::JointPowersAll outputs = mJointController->computeControl(controlInput, mControlSetpoint);
		
		for (size_t i = 0; i < jointStates.size(); i++) {
			jointStates.at(i).setpoint_pos = lastJointStates.at(i).motionState[0];
			jointStates.at(i).setpoint_vel = lastJointStates.at(i).motionState[1];
		}
		
		checkAndSetPWM(jointStates, outputs);
	}
		break;
		
	case TRAJECTORY: {
	    mControlSetpoint.at(GRIPPER_INDEX) = Vec2f(mRawJointPowers.at(GRIPPER_INDEX), 0);
	    robot::JointMotionStatesArm armSetpoint;
		TrajectoryPathBuffer::PointState ps = mTrajectoryPathBuffer.getNextSetpoint(&armSetpoint, hw::clock::getMsTick() - mTrajectoryStartTime_ms);
		if (ps == TrajectoryPathBuffer::VALID) {
		    std::copy(armSetpoint.begin(), armSetpoint.end(), mControlSetpoint.begin());
		} else if (ps == TrajectoryPathBuffer::EMPTY) {
			// if trajectory buffer is empty, keep previous mControlSetpoint
			//for (size_t i = 0; i < robot::ArmConfig::NUM_JOINTS; i++) {
			//    mControlSetpoint.at(i) = Vec2f(lastJointStates.at(i).motionState[0], 0);
			// }
		} else if (ps == TrajectoryPathBuffer::FINISHED) {
		    std::copy(armSetpoint.begin(), armSetpoint.end(), mControlSetpoint.begin());
		    mRelaseTrajectoryTicks = TRAJECTORY_FINISHED_RELEASE_TICKS;
			// if trajectory finished, hold position for TRAJECTORY_FINISHED_RELEASE_TICKS

			for (size_t i = 0; i < mRawJointPowers.size(); i++) {
			    mRawJointPowers.at(i) = mControlSetpoint.at(i)[0];
			    // controlSetpoint.at(i) = Vec2f(lastJointStates.at(i).motionState[0], 0);
			}

		    // keep last mControlSetpoint
			mCurrentState = DIRECT_CONTROLLER;
		}
		
		robot::JointPowersAll outputs = mJointController->computeControl(controlInput, mControlSetpoint);
		
		for (size_t i = 0; i < jointStates.size(); i++) {
			jointStates.at(i).setpoint_pos = mControlSetpoint.at(i)[0];
			jointStates.at(i).setpoint_vel = mControlSetpoint.at(i)[1];
		}
		
		checkAndSetPWM(jointStates, outputs);
	}
		break;
		
	case DIRECT_CONTROLLER:
	{
	    /*
	    if(mRelaseTrajectoryTicks > 0) {
	        mRelaseTrajectoryTicks--;
	    } else if(mRelaseTrajectoryTicks == 0) {
	        mRelaseTrajectoryTicks = -1;
	        mArmHardware->breakMotors();
	        mCurrentState = BREAK;
	        break;
	    } */

		for (size_t i = 0; i < mControlSetpoint.size(); i++) {
		    mControlSetpoint.at(i) = Vec2f(mRawJointPowers.at(i), 0);
		}
		
		robot::JointPowersAll outputs = mJointController->computeControl(controlInput, mControlSetpoint);
		
		for (size_t i = 0; i < jointStates.size(); i++) {
			jointStates.at(i).setpoint_pos = mControlSetpoint.at(i)[0];
			jointStates.at(i).setpoint_vel = mControlSetpoint.at(i)[1];
		}
		checkAndSetPWM(jointStates, outputs);
	}
		break;
	}
}

void MotionManager::checkAndSetPWM(JointStatesMsgAll& states, robot::JointPowersAll& powers) {
	mArmHardware->setJointPowers(powers);
	(void)states;
	// TODO check error state
	for (size_t i = 0; i < states.size(); i++) {
		states.at(i).torque = powers.at(i);
	}
}

} /* namespace path */

