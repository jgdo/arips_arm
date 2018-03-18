/*
 * hw.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: jgdo
 */

#include <hw/hw.h>
#include <hw/AdafruitV2Motor.h>

#include <Arduino.h>

namespace hw {

void init() {
	analogReadResolution(12);

	static Adafruit_MotorShield AFMS_L0(0x60);
	static Adafruit_MotorShield AFMS_L1(0x61);

	static AdafruitV2Motor l0_m1("Level0_M1", AFMS_L0.getMotor(1));
	static AdafruitV2Motor l0_m2("Level0_M1", AFMS_L0.getMotor(2));
	static AdafruitV2Motor l0_m3("Level0_M1", AFMS_L0.getMotor(3));
	static AdafruitV2Motor l0_m4("Level0_M1", AFMS_L0.getMotor(4));
	static AdafruitV2Motor l1_m1("Level0_M1", AFMS_L1.getMotor(1));
	static AdafruitV2Motor l1_m2("Level0_M1", AFMS_L1.getMotor(2));
	static AdafruitV2Motor l1_m3("Level0_M1", AFMS_L1.getMotor(3));
	static AdafruitV2Motor l1_m4("Level0_M1", AFMS_L1.getMotor(4));

	actuator::adafruitV2MotorL0_M1 = &l0_m1;
	actuator::adafruitV2MotorL0_M2 = &l0_m2;
	actuator::adafruitV2MotorL0_M3 = &l0_m3;
	actuator::adafruitV2MotorL0_M4 = &l0_m4;
	actuator::adafruitV2MotorL1_M1 = &l1_m1;
	actuator::adafruitV2MotorL1_M2 = &l1_m2;
	actuator::adafruitV2MotorL1_M3 = &l1_m3;
	actuator::adafruitV2MotorL1_M4 = &l1_m4;
}

float adc::getChannel(size_t channel) {
	return analogRead(channel);
}

uint32_t clock::getMsTick() {
	return millis();
}

namespace actuator {
Actuator* adafruitV2MotorL0_M1;
Actuator* adafruitV2MotorL0_M2;
Actuator* adafruitV2MotorL0_M3;
Actuator* adafruitV2MotorL0_M4;
Actuator* adafruitV2MotorL1_M1;
Actuator* adafruitV2MotorL1_M2;
Actuator* adafruitV2MotorL1_M3;
Actuator* adafruitV2MotorL1_M4;
}

} /* namespace hw */
