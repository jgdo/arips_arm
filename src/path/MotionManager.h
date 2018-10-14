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
#include <hw/hw.h>
#include <path/SingleTargetPathProvider.h>
#include <path/TrajectoryPathBuffer.h>

#include <robot/RobotArmHardware.h>

namespace path {

class MotionManager {
public:
	typedef std::array<arips_arm_msgs::JointState, robot::ArmConfig::NUM_ALL_JOINTS> JointStatesMsgAll;
	
	enum State {
		IDLE = 0, // motors are turned off
		BREAK, // motors are short-cut
		HOLD, // motors should hold position
		RAW_MOTORS, // raw mode
		DIRECT_JOINTS, // direct joint control with limit checks
		DIRECT_CONTROLLER, // provide joint setpoints directly instead over a trajectory
		TRAJECTORY, // trajectory (setpoint sequence)
	};
	
	static constexpr int TRAJECTORY_FINISHED_RELEASE_TICKS = 500;

	/**
	 * 
	 */
	MotionManager(robot::RobotArmController* controller, robot::RobotArmHardware* arm);
	~MotionManager();
	
	/**
	 * Called periodically to observe joint states
	 */
	void onObserveTick();

	/**
	 * Called periodically on every control tick
	 * 
	 * @param jointStates will be filled with current joint states
	 */
    void onControlTick(JointStatesMsgAll& jointStates);
	
	
	/**
	 * Start following trajectory in trajectory buffer
	 */
	void enterFollowingTrajectory();
	
	/**
	 * Reset trajectory buffer and time. Does not enter TAJECTORY mode automatically
	 */
	void resetTrajectory(size_t trajSize);

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
	
	void setRawMotorPowers(const robot::JointPowersAll& powers);
	
	/**
	 * Set gripper target position. If not in TRAJECTORY or DIRECT_CONTROLLER state, set state to DIRECT_CONTROLLER
	 */
	void setGripperGoal(float goal);

private:
	State mCurrentState = IDLE;
	
	robot::RobotArmController* mJointController;
	robot::RobotArmHardware* mArmHardware;
	
	// SingleTargetPathProvider mSingleTargetProvider;
	TrajectoryPathBuffer mTrajectoryPathBuffer;
	
	uint32_t mTrajectoryStartTime_ms = 0; // time when trajectory started
	
	int32_t mRelaseTrajectoryTicks = -1; // control ticks after which to go into BREAK mode once trajectory has finished, invalid if negative

	/**
	 * In RAW_MOTORS mode: raw motor pwm setpoint values
	 * In DIRECT_JOINTS mode: joint effort setpoint values
	 * In DIRECT_CONTROLLER mode: joint angle setpoint values as controller input
	 * In TRAJECTORY mode: .at(GRIPPER_INDEX) is gripper setpoint
	 */
	robot::JointPowersAll mRawJointPowers;
	
	robot::JointMotionStatesAll mControlSetpoint; /** holds most recent trajectory setpoint */

	void checkAndSetPWM(JointStatesMsgAll& states, robot::JointPowersAll& powers);
};

} /* namespace path */

#endif /* PATH_MOTIONMANAGER_H_ */
