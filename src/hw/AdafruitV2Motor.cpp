/*
 * AdafruitV2Motor.cpp
 *
 *  Created on: Mar 15, 2018
 *      Author: jgdo
 */

#include <hw/AdafruitV2Motor.h>

#include <algorithm>

namespace hw {

} /* namespace hw */

hw::AdafruitV2Motor::AdafruitV2Motor(const char* name, Adafruit_DCMotor* motor) :
		mName(name), mAdafruitMotor(motor) {
}

const char* hw::AdafruitV2Motor::name() const {
	return mName;
}

void hw::AdafruitV2Motor::doBreak() {
	mAdafruitMotor->run(RELEASE);
	mAdafruitMotor->setSpeed12(4095);
}

void hw::AdafruitV2Motor::release() {
	mAdafruitMotor->run(RELEASE);
	mAdafruitMotor->setSpeed12(0);
}

float hw::AdafruitV2Motor::apply(float value) {
	if (value > 0) {
		mAdafruitMotor->run(FORWARD);
		mAdafruitMotor->setSpeed12(std::min(int(value * 4095 + 0.5f), 4095));
	} else {
		mAdafruitMotor->run(BACKWARD);
		mAdafruitMotor->setSpeed12(std::min(int(-value * 4095 + 0.5f), 4095));
	}

	return std::clamp(value, -1.0f, 1.0f);
}
