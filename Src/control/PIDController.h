/*
 * PIDController.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_PIDCONTROLLER_H_
#define CONTROL_PIDCONTROLLER_H_

#include <control/Controller.h>

#include <utl/ParameterServer.h>

#include <Eigen/Dense>

namespace ctrl {

struct PIDParameters: public utl::ParameterGroup {	
	PIDParameters(const char* name):
		utl::ParameterGroup(name),
		P("p", this, 40.0f),
		I("i", this, 0.2f),
		D("d", this, 1.5f)
	{
	}
	
	utl::FloatParam P, I, D;
};

class PIDController: public Controller<Eigen::Vector2f> {
public:
	PIDController(float outMin, float outMax);
	
	virtual void reset() override;
	
	virtual float computeControl(ValueType input, ValueType setpoint) override;
	
private:	
	PIDParameters params;
	
	float outMin, outMax;
	
	float isum = 0;
};

} /* namespace ctrl */

#endif /* CONTROL_PIDCONTROLLER_H_ */
