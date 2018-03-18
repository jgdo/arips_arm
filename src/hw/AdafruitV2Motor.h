/*
 * AdafruitV2Motor.h
 *
 *  Created on: Mar 15, 2018
 *      Author: jgdo
 */

#ifndef HW_ADAFRUITV2MOTOR_H_
#define HW_ADAFRUITV2MOTOR_H_

#include <hw/Actuator.hpp>

#include <Adafruit_MotorShield.h>

namespace hw {

class AdafruitV2Motor: public Actuator {
public:
	AdafruitV2Motor(const char* name, Adafruit_DCMotor* motor);

	virtual const char* name() const;

	/**
	 * break the motors (e.g. by short-cutting)
	 */
	virtual void doBreak();

	/**
	 * Make motors free-running
	 */
	virtual void release();

	/**
	 * Activate motor and apply power
	 *
	 * @param value power, [-1, 1] (unit not specified)
	 * @return power actually applied
	 */
	virtual float apply(float value);

private:
	const char* mName;
	Adafruit_DCMotor *mAdafruitMotor;
};

} /* namespace hw */

#endif /* HW_ADAFRUITV2MOTOR_H_ */
