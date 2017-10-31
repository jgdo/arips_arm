/*
 * MotionManager.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#include <path/MotionManager.h>

#include <hw/ControllerHardware.h>

namespace path {

MotionManager::MotionManager(ctrl::Controller<Eigen::Vector2f>* controller, hw::Actuator* actuator, JointStateObserver* jso) :
		mJointStateObserver(jso),
		mActuator(actuator),
		mJointController(controller)
{
}

MotionManager::~MotionManager() {

}

void MotionManager::setNewSingleGoal(float position) {
	mCurrentState = SINGLE_GOAL;
	mPathStartTimeMs = hw::clock::getTimeMs();
	mSingleTargetProvider.setTarget(0.0, position, mJointStateObserver->getCurrentJointState().motionState);
}

arips_arm_msgs::JointState MotionManager::onControlTick() {
	arips_arm_msgs::JointState res;
	
	auto jointState = mJointStateObserver->getCurrentJointState();
	float dtStart = (hw::clock::getTimeMs() - mPathStartTimeMs) * 0.001F;
	
	res.adc_raw = jointState.adc_raw;
	res.position = jointState.motionState[0];
	res.velocity = jointState.motionState[1];
	
	switch(mCurrentState) {
	case IDLE: // motors are turned off
		mJointController->doReleaseMotor();
		break;
		
	case BREAK: // motors are short-cut
		mJointController->doBreak();
		break;
		
	case HOLD: // motors should hold position
		res.pwm = mJointController->control(jointState.motionState, Vec2f(jointState.motionState(0), 0.0f));
		res.setpoint_pos = jointState.motionState[0];
		res.setpoint_vel = jointState.motionState[1];
		mActuator->set(res.pwm);
		break;
		
	case SINGLE_GOAL: { // moving to a final goal
		Vec2f goal = mSingleTargetProvider.getSetpoint(dtStart, jointState.motionState);
		res.pwm = mJointController->control(jointState.motionState, goal);
		res.setpoint_pos = goal[0];
		res.setpoint_vel = goal[1];
		mActuator->set(res.pwm);
	}
		break;
	}
	
	return res;
}

} /* namespace path */
