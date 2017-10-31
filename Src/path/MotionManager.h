/*
 * MotionManager.h
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#ifndef PATH_MOTIONMANAGER_H_
#define PATH_MOTIONMANAGER_H_

#include <control/Controller.h>
#include <hw/ControllerHardware.h>
#include <path/SingleTargetPathProvider.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <arips_arm_msgs/JointState.h>

namespace path {

class JointStateObserver {
public:
	JointStateObserver(): mLastPos(hw::adc::getAll()[1]), mLastVel(0), mLastMs(hw::clock::getTimeMs()) {
	}
	
	inline ctrl::JointState getCurrentJointState() {
		auto adc = hw::adc::getAll()[1];
		float pos = adc / 4096.0f;
		
		uint32_t now = hw::clock::getTimeMs();
		uint32_t dt = now - mLastMs;
		
		if(dt > 5) {
			mLastVel = (pos - mLastPos) / (dt * 0.001f);
			mLastPos = pos;
			mLastMs = now;
		} 
		
		return ctrl::JointState { Vec2f(pos, mLastVel), adc };
	}
	
private:	
	float mLastPos, mLastVel;
	uint32_t mLastMs;
};

class MotionManager {
public:
	enum State {
		IDLE, // motors are turned off
		BREAK, // motors are short-cut
		HOLD, // motors should hold position
		SINGLE_GOAL, // moving to a final goal
	};
	
	/**
	 * @param[in] controller joint motor controller
	 */
	MotionManager(ctrl::Controller<Eigen::Vector2f>* controller, hw::Actuator* actuator, JointStateObserver* jso);
	~MotionManager();
	
	/**
	 * Called periodically on every control tick
	 * 
	 * @param[in] dt delta time since last call
	 */
	arips_arm_msgs::JointState onControlTick();
	
	/**
	 * Cancel current goal and set new single goal
	 * 
	 * @param[in] point goal movement point
	 */
	void setNewSingleGoal(float position);
	
	inline JointStateObserver* getJointStateObserver() {
		return mJointStateObserver;
	}
		
private:
	State mCurrentState = IDLE;
	
	JointStateObserver* mJointStateObserver;
	
	hw::Actuator* mActuator;
	
	SingleTargetPathProvider mSingleTargetProvider;
	
	ctrl::Controller<Eigen::Vector2f>* mJointController;
	
	uint32_t mPathStartTimeMs = 0;
};

} /* namespace path */

#endif /* PATH_MOTIONMANAGER_H_ */
