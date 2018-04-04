/*
 * JointBlock.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jgdo
 */

#ifndef ROBOT_ROBOTARMHARDWARE_H_
#define ROBOT_ROBOTARMHARDWARE_H_

#include <array>

#include <utl/vecdef.h>

#include "ArmConfig.h"
#include <hw/Actuator.hpp>
#include "JointStateObserver.h"
#include "RobotModel.h"

namespace robot {

typedef std::array<float, ArmConfig::NUM_JOINTS> JointPowers;
typedef std::array<JointState, ArmConfig::NUM_JOINTS> JointStates;

class RobotArmHardware {
public:
	RobotArmHardware(const RobotModel& model,
					std::array<hw::Actuator*, ArmConfig::NUM_JOINTS> const& actuators,
			 	 	std::array<JointStateObserver*, ArmConfig::NUM_JOINTS> const& observers);
	/**
	 * Shortcut all motors to create a breaking effect.
	 */
	void breakMotors();
	
	/**
	 * Release motor power for free running
	 */
	void releaseMotors();
	
	/**
	 * Apply power to all joints. If a joint is about to exceed its limits, no power is applied. 
	 * 
	 * Note that there is not necessary a 1-1 relation between joint and motor
	 * 
	 * @params powers try to apply given power, set value to actually applied power
	 */
	void setJointPowers(JointPowers& powers);
	
	/**
	 * Apply power to all motors. No joint limits are checked!
	 */
	void setRawMotorPowers(const JointPowers& powers);
	
	/**
	 * Read the current joint states
	 */
	void readJointStates();
	
	/**
	 * Get joint states since last readJointStates() call
	 */
	const JointStates& getJointStates();
	
private:
	const RobotModel& mModel;
	std::array<hw::Actuator*, ArmConfig::NUM_JOINTS> mActuators;
	std::array<JointStateObserver*, ArmConfig::NUM_JOINTS> mObservers;
	JointStates mLastJointStates;
	
	bool limitJointPower(size_t index, JointPowers::value_type& power);
};

} /* namespace robot */

#endif /* ROBOT_ROBOTARMHARDWARE_H_ */
