/*
 * JointBlock.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jgdo
 */

#include <robot/RobotArmHardware.h>

namespace robot {

RobotArmHardware::RobotArmHardware(const RobotModel& model, 
																	 std::array<hw::Actuator*, ArmConfig::NUM_JOINTS> const& actuators,
																	 std::array<JointStateObserver*, ArmConfig::NUM_JOINTS> const& observers) :
		mModel(model), mActuators(actuators), mObservers(observers) {
}

void RobotArmHardware::breakMotors() {
	for (auto& a : mActuators) {
		a->doBreak();
	}
}

void RobotArmHardware::releaseMotors() {
	for (auto& a : mActuators) {
		a->release();
	}
}

void RobotArmHardware::setJointPowers(JointPowers& powers) {
	for (size_t i = 0; i < ArmConfig::NUM_JOINTS; i++) {
		auto& state = mLastJointStates.at(i);
		auto& limits = mModel.getJointLimits();
		
		// stop motors if moving to outside limits
		float predictedNextPos = state.motionState[0] + state.motionState[1] * ArmConfig::CONTROL_PERIOD_S;
		if ((predictedNextPos <= limits.at(i).minAngle && state.motionState[1] < 0)
				|| (predictedNextPos >= limits.at(i).maxAngle && state.motionState[1] > 0)) {
			powers.at(i) = 0;
			mActuators.at(i)->doBreak();
		} else {
			mActuators.at(i)->apply(powers.at(i));
		}
	}
}

void RobotArmHardware::readJointStates() {
	for (size_t i = 0; i < mObservers.size(); i++) {
		mLastJointStates.at(i) = mObservers.at(i)->observeJointState();
	}
}

void RobotArmHardware::setRawMotorPowers(const JointPowers& powers) {
	for (size_t i = 0; i < ArmConfig::NUM_JOINTS; i++) {
			mActuators.at(i)->apply(powers.at(i));
	}
}

const JointStates& RobotArmHardware::getJointStates() {
	return mLastJointStates;
}

} /* namespace robot */
