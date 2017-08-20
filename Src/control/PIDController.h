/*
 * PIDController.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_PIDCONTROLLER_H_
#define CONTROL_PIDCONTROLLER_H_

#include <control/Controller.h>

#include <utl/ParameterStore.h>

namespace ctrl {
struct PIDParameters {
	float P = 40, I = 0.2, D=150;
};

class PIDController: public Controller<float> {
public:
	PIDController(float outMin, float outMax);
	
	virtual void reset() override;
	
	virtual float control(float input, float setpoint) override;
	
private:
	utl::ParameterServer<PIDParameters> server;
	
	float outMin, outMax;
	
	
	
	float last = 0.5;
	float isum = 0;
	
	
	
	PIDParameters params;
};

} /* namespace ctrl */

#endif /* CONTROL_PIDCONTROLLER_H_ */
