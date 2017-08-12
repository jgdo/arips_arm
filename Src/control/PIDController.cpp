/*
 * PIDController.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#include <control/PIDController.h>

namespace ctrl {
float PIDController::control(float input, float setpoint) {
	static float last = 0.5;
	static float isum = 0;
	
	float err = setpoint-input;
	float i = isum;
	float d = last - input;
	isum += err;
	last = input;
	
	return err*3 + i*0.005 + d * 15;
}

} /* namespace ctrl */

