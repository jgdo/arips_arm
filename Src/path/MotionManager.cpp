/*
 * MotionManager.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#include <path/MotionManager.h>

#include <hw/ControllerHardware.h>
#include <hw/ArmConfig.h>

namespace path {

MotionManager::MotionManager(ctrl::Controller<Eigen::Vector2f>* controller, hw::Actuator* actuator,
		JointStateObserver* jso) :
		mJointStateObserver(jso), mActuator(actuator), mJointController(controller) {
}

MotionManager::~MotionManager() {
	
}

void MotionManager::setNewSingleGoal(float position) {
	mCurrentState = SINGLE_GOAL;
	mControlCycleCount = 0;
	mPathStartTimeMs = hw::clock::getTimeMs();
	mSingleTargetProvider.setTarget(0.0, position, mJointStateObserver->getCurrentJointState().motionState);
}

void MotionManager::startFollowingTrajectory() {
	mCurrentState = TRAJECTORY;
	mControlCycleCount = 0;
	mPathStartTimeMs = hw::clock::getTimeMs();
}

void MotionManager::stop() {
	mCurrentState = BREAK;
	mControlCycleCount = 0;
}

void MotionManager::release() {
	mCurrentState = IDLE;
	mControlCycleCount = 0;
}

arips_arm_msgs::JointState MotionManager::onControlTick() {
	arips_arm_msgs::JointState res;
	
	auto jointState = mJointStateObserver->getCurrentJointState();
	float dtStart = (hw::clock::getTimeMs() - mPathStartTimeMs) * 0.001F;
	
	res.adc_raw = jointState.adc_raw;
	res.position = jointState.motionState[0];
	res.velocity = jointState.motionState[1];
	
	switch (mCurrentState) {
	case IDLE: // motors are turned off
		mActuator->set(0);
		break;
		
	case BREAK: // motors are short-cut
		mActuator->stop();
		break;
		
	case HOLD: // motors should hold position
		res.pwm = mJointController->control(jointState.motionState, Vec2f(jointState.motionState(0), 0.0f));
		res.setpoint_pos = jointState.motionState[0];
		res.setpoint_vel = jointState.motionState[1];
		checkAndSetPWM(res);
		break;
		
	case SINGLE_GOAL: { // moving to a final goal
		mControlCycleCount++;
		Vec2f goal = mSingleTargetProvider.getSetpoint(dtStart, jointState.motionState);
		res.pwm = mJointController->control(jointState.motionState, goal);
		res.setpoint_pos = goal[0];
		res.setpoint_vel = goal[1];
		checkAndSetPWM(res);
	}
		break;
		
	case TRAJECTORY:
		Vec2f goal = jointState.motionState;
		TrajectoryPathBuffer::PointState ps = mTrajectoryPathBuffer.getNextSetpoint(jointState.motionState, &goal);
		if (ps == TrajectoryPathBuffer::VALID) {
			mControlCycleCount++;
		} else if (ps == TrajectoryPathBuffer::EMPTY) {
			// if trajectory buffer is empty, hold position
			goal[1] = 0;
		} else if (ps == TrajectoryPathBuffer::FINISHED) {
			// if trajectory finished, hold position
			goal[1] = 0;
			mCurrentState = HOLD;
		}
		
		res.pwm = mJointController->control(jointState.motionState, goal);
		res.setpoint_pos = goal[0];
		res.setpoint_vel = goal[1];
		checkAndSetPWM(res);
		break;
	}
	
	return res;
}

void MotionManager::checkAndSetPWM(arips_arm_msgs::JointState& state) {
	// stop motors if moving to outside limits
	float predictedNextPos = state.position + state.velocity * ArmConfig::CONTROL_PERIOD_S;
	if ((predictedNextPos <= ArmConfig::JOINT_LIMIT_MIN && state.velocity < 0)
			|| (predictedNextPos >= ArmConfig::JOINT_LIMIT_MAX && state.velocity > 0)) {
		state.pwm = 0;
		mActuator->stop();
	} else {
		mActuator->set(state.pwm);
	}
}

} /* namespace path */
