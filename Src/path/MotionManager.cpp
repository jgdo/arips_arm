/*
 * MotionManager.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#include <path/MotionManager.h>

namespace path {

MotionManager::MotionManager(ctrl::Controller<Eigen::Vector2f>* controller) :
		mJointController(controller)
{
}

MotionManager::~MotionManager() {

}

void MotionManager::setNewSingleGoal(float position) {
	mCurrentState = SINGLE_GOAL;
	mPathStartTime = ros::Time::now();
	mSingleTargetProvider.setTarget(0.0, position, mJointStateObserver.getCurrentJointState().motionState);
}

void MotionManager::onControlTick(float dt) {
	auto jointState = mJointStateObserver.getCurrentJointState().motionState;
	auto now = ros::Time::now();
	
	switch(mCurrentState) {
	case IDLE: // motors are turned off
		mJointController->doReleaseMotor();
		break;
		
	case BREAK: // motors are short-cut
		mJointController->doBreak();
		break;
		
	case HOLD: // motors should hold position
		mJointController->control(jointState, Vec2f(jointState(0), 0.0f));
		break;
		
	case SINGLE_GOAL: // moving to a final goal
		mJointController->control(jointState, mSingleTargetProvider.getSetpoint((now-mPathStartTime).toSec(), jointState));
		break;
	}
}

} /* namespace path */
