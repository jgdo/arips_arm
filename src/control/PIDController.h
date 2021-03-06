/*
 * PIDController.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_PIDCONTROLLER_H_
#define CONTROL_PIDCONTROLLER_H_

#include <control/Controller.h>

#include <rosutil/ParameterServer.h>

#include <utl/vecdef.h>

namespace ctrl {

struct PIDParameters: public rosutl::ParameterGroup {
	PIDParameters(const char* name):
		rosutl::ParameterGroup(name),
		P("p", this, 1.0f),
		I("i", this, 0.0f),
		D("d", this, 0.0f)
	{
	}
	
	rosutl::FloatParam P, I, D;
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
