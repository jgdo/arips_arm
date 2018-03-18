/*
 * VelocityPIDController.h
 *
 *  Created on: Aug 20, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_VELOCITYPIDCONTROLLER_H_
#define CONTROL_VELOCITYPIDCONTROLLER_H_

#include "PIDController.h"

namespace ctrl {

class VelocityPIDController: public Controller<Eigen::Vector2f> {
public:

	VelocityPIDController(const char* name, float outMin, float outMax);

	virtual void reset() override;
	virtual float computeControl(ValueType input, ValueType setpoint) override;

	PIDParameters params;
	
private:
	float outMin, outMax;
	
	float isum = 0;
};

} /* namespace ctrl */

#endif /* CONTROL_VELOCITYPIDCONTROLLER_H_ */
