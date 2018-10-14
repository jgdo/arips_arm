/*
 * JointBlock.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jgdo
 */

#include <robot/RobotArmHardware.h>
#include <tuple>

namespace robot {

RobotArmHardware::RobotArmHardware(const RobotModel& model,
		std::array<hw::Actuator*, ArmConfig::NUM_ALL_JOINTS> const& actuators,
		std::array<JointStateObserver*, ArmConfig::NUM_ALL_JOINTS> const& observers) :
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

bool RobotArmHardware::limitJointPower(size_t i, JointPowersAll::value_type& power) {
	auto& state = mLastJointStates.at(i);
	auto& limits = mModel.getJointLimits();
	
	// stop motors if moving to outside limits
	float predictedNextPos = state.motionState[0] + state.motionState[1] * ArmConfig::CONTROL_PERIOD_S;
	if ((predictedNextPos <= limits.at(i).minAngle && state.motionState[1] < 0)
			|| (predictedNextPos >= limits.at(i).maxAngle && state.motionState[1] > 0)) {
		power = 0;
		return false;
	} else {
		power = std::clamp(power, -1.0f, 1.0f);
		return true;
	}
}

void RobotArmHardware::setJointPowers(JointPowersAll& powers) {
	static_assert(ArmConfig::NUM_ALL_JOINTS == 6, "This RobotArmHardware specialized on a 5 DOF + gripper robot");
	
	for (size_t i = 0; i < 3; i++) {
		if(limitJointPower(i, powers.at(i))) {
			mActuators.at(i)->apply(powers.at(i));
		} else {
			mActuators.at(i)->doBreak();
		}
	}
	
	if(limitJointPower(3, powers.at(3)) && limitJointPower(4, powers.at(4))) {
		float p3 = std::clamp(powers.at(3) - powers.at(4), -1.0f, 1.0f);
		float p4 = std::clamp(powers.at(3) + powers.at(4), -1.0f, 1.0f);
		
		mActuators.at(3)->apply(p3);
		mActuators.at(4)->apply(p4);
		
	} else {
		powers.at(3) = powers.at(4) = 0;
		mActuators.at(3)->doBreak();
		mActuators.at(4)->doBreak();
	}

	if(true || limitJointPower(5, powers.at(5))) {
        mActuators.at(5)->apply(powers.at(5));
    } else {
        mActuators.at(5)->doBreak();
    }
}

void RobotArmHardware::readJointStates(robot::JointPowersAll const& lastTorque) {
	for (size_t i = 0; i < mObservers.size(); i++) {
		mLastJointStates.at(i) = mObservers.at(i)->observeJointState(lastTorque.at(i));
	}
}

void RobotArmHardware::setRawMotorPowers(const JointPowersAll& powers) {
    static_assert(std::tuple_size<decltype(mActuators)>::value == std::tuple_size<JointPowersAll>::value,
            "sizes must match.");

	for (size_t i = 0; i < mActuators.size(); i++) {
		mActuators.at(i)->apply(powers.at(i));
	}
}

const JointStatesAll& RobotArmHardware::getJointStates() {
	return mLastJointStates;
}

} /* namespace robot */
