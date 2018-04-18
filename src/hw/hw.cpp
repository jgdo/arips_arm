/*
 * hw.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: jgdo
 */

#include <hw/hw.h>
#include <hw/AdafruitV2Motor.h>

#include <Arduino.h>
#include <Servo.h>

#include <stdexcept>

namespace hw {

void init() {
	analogReadResolution(12);

	pmc_enable_periph_clk(ID_ADC); // To use peripheral, we must enable clock distributon to it
    adc_init(ADC, SystemCoreClock, ADC_FREQ_MAX, ADC_STARTUP_FAST); // initialize, set maximum posibble speed
    adc_disable_interrupt(ADC, 0xFFFFFFFF);
    adc_set_resolution(ADC, ADC_12_BITS);
    adc_configure_power_save(ADC, 0, 0); // Disable sleep
    adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1); // Set timings - standard values
    adc_set_bias_current(ADC, 1); // Bias current - maximum performance over current consumption
    adc_stop_sequencer(ADC); // not using it
    adc_disable_tag(ADC); // it has to do with sequencer, not using it
    adc_disable_ts(ADC); // deisable temperature sensor
    adc_configure_trigger(ADC, ADC_TRIG_SW, 1); // triggering from software, freerunning mode
    adc_disable_all_channel(ADC);

	static Adafruit_MotorShield AFMS_L0(0x60);
	static Adafruit_MotorShield AFMS_L1(0x61);

	Wire1.begin();
	AFMS_L0.begin();
	AFMS_L1.begin();

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

	actuator::md25Motors.init();

	Serial.begin(115200);
	Serial.println("Init done.");
}

float adc::getChannel(size_t channel) {
    analogRead(channel);
	return (analogRead(channel)+ analogRead(channel) + analogRead(channel) + analogRead(channel)) / 4.0f;
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

MD25Motors md25Motors;
}

} /* namespace hw */
