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

namespace path {

class JointStateObserver {
public:
	inline ctrl::JointState getCurrentJointState() {
		auto adc = hw::adc::getAll();
		return ctrl::JointState { Vec2f(adc[1]/4096f, 0.0) }; // TODO: measure velocity
	}
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
	MotionManager(ctrl::Controller<Eigen::Vector2f>* controller);
	~MotionManager();
	
	/**
	 * Called periodically on every control tick
	 * 
	 * @param[in] dt delta time since last call
	 */
	void onControlTick(float dt);
	
	/**
	 * Cancel current goal and set new single goal
	 * 
	 * @param[in] point goal movement point
	 */
	void setNewSingleGoal(float position);
		
private:
	State mCurrentState = IDLE;
	
	JointStateObserver mJointStateObserver;
	
	SingleTargetPathProvider mSingleTargetProvider;
	
	ctrl::Controller<Eigen::Vector2f>* mJointController;
	
	ros::Time mPathStartTime;
};

} /* namespace path */

#endif /* PATH_MOTIONMANAGER_H_ */
