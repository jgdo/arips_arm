/*
 * MotionManager.h
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#ifndef PATH_MOTIONMANAGER_H_
#define PATH_MOTIONMANAGER_H_

#include <arips_arm_msgs/JointState.h>

#include <control/Controller.h>
#include <hw/ControllerHardware.h>
#include <path/SingleTargetPathProvider.h>
#include <path/TrajectoryPathBuffer.h>

#include <robot/RobotArmHardware.h>

namespace path {

class MotionManager {
public:
	typedef std::array<arips_arm_msgs::JointState, robot::ArmConfig::NUM_JOINTS> JointStatesMsg;
	
	enum State {
		IDLE = 0, // motors are turned off
		BREAK, // motors are short-cut
		HOLD, // motors should hold position
		RAW_MOTORS, // raw mode
		DIRECT_JOINTS, // direct joint control with limit checks
		DIRECT_CONTROLLER, // provide joint setpoints directly instead over a trajectory
		TRAJECTORY, // trajectory (setpoint sequence)
	};
	
	/**
	 * 
	 */
	MotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm);
	~MotionManager();
	
	/**
	 * Called periodically on every control tick
	 * 
	 * @param jointStates will be filled with current joint states
	 */
	void onControlTick(JointStatesMsg& jointStates);
	
	
	/**
	 * Start following trajectory in trajectory buffer
	 */
	void startFollowingTrajectory();
	
	/**
	 * Cancel any movement goals and stop
	 */
	void stop();
	
	/**
	 * Set state to idle and release motors
	 */
	void release();
	
	/**
	 * Set motor powers to 0 and enter raw mode
	 */
	void enterRawMode();
	
	/**
	 * Direct joint control with limits check
	 */
	void enterDirectJointsMode();
	
	void enterDirectControllerMode();
	
	inline TrajectoryPathBuffer& getTrajectoryBuffer() {
		return mTrajectoryPathBuffer;
	}
	
	inline State getState() const {
		return mCurrentState;
	}
	
	inline uint32_t getControlCycleCount() const {
		return mControlCycleCount;
	}
	
	void setRawMotorPowers(const robot::JointPowers& powers);
	
private:
	State mCurrentState = IDLE;
	
	robot::RobotArmController* mJointController;
	robot::RobotArmHardware* mArmHardware;
	
	// SingleTargetPathProvider mSingleTargetProvider;
	TrajectoryPathBuffer mTrajectoryPathBuffer;
	
	uint32_t mPathStartTimeMs = 0;
	uint32_t mControlCycleCount = 0;
	
	/**
	 * In RAW_MOTORS mode: raw motor pwm setpoint values
	 * In DIRECT_JOINTS mode: joint effort setpoint values
	 * In DIRECT_CONTROLLER mode: joint angle setpoint values as controller input
	 */
	robot::JointPowers mRawJointPowers;
	
	void checkAndSetPWM(JointStatesMsg& states, robot::JointPowers& powers);
};

} /* namespace path */

#endif /* PATH_MOTIONMANAGER_H_ */
