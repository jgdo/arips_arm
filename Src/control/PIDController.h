/*
 * PIDController.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_PIDCONTROLLER_H_
#define CONTROL_PIDCONTROLLER_H_

#include <control/Controller.h>

namespace ctrl {

class PIDController: public Controller {
public:
	PIDController(float outMin, float outMax);
	
	virtual void reset() override;
	
	virtual float control(float input, float setpoint) override;
	
private:
	float outMin, outMax;
	float last = 0.5;
	float isum = 0;
		
	float P = 5, I = 0.3, D=50;
};

} /* namespace ctrl */

#endif /* CONTROL_PIDCONTROLLER_H_ */
