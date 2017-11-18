/*
 * VelocityPIDController.h
 *
 *  Created on: Aug 20, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_VELOCITYPIDCONTROLLER_H_
#define CONTROL_VELOCITYPIDCONTROLLER_H_

#include <control/Controller.h>

#include <Eigen/Dense>

#include <utl/ParameterStore.h>

namespace ctrl {

class VelocityPIDController: public Controller<Eigen::Vector2f> {
public:
	struct Parameters {
		float P = 40, I = 0.2, D = 1.5f;
	};

	VelocityPIDController(float outMin, float outMax);

	virtual void reset() override;
	virtual float control(ValueType input, ValueType setpoint) override;

private:
	// utl::ParameterServer<Parameters> server;

	float outMin, outMax;
	
	float isum = 0;

	Parameters params;
};

} /* namespace ctrl */

#endif /* CONTROL_VELOCITYPIDCONTROLLER_H_ */
