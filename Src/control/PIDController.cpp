/*
 * PIDController.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#include <control/PIDController.h>

#include <utl/ParameterStore.h>

namespace ctrl {

float PIDController::control(float input, float setpoint) {	
	P = utl::ParameterStore::get<float>(utl::PS_ID_PID_P);
	I = utl::ParameterStore::get<float>(utl::PS_ID_PID_I);
	D = utl::ParameterStore::get<float>(utl::PS_ID_PID_D);
	
	float err = setpoint-input;
	float d = last - input;
	isum += err *I;
	last = input;
	
	float out = err*P + isum + d * D;
	
	// anti-windup
	if(out < outMin) {
		out = outMin;
		
		if(isum < 0) {
			float diff = outMin - out; // positive
			isum += diff;
			if(isum > 0) {
				isum = 0;
			}
		}
	} else if(out > outMax) {
		out = outMax;
		
		if(isum > 0) {
			float diff = out-outMax; // positive
			isum -= diff;
			if(isum < 0) {
				isum = 0;
			}
		}
	}
	
	return out;
}

} /* namespace ctrl */

ctrl::PIDController::PIDController(float outMin, float outMax): outMin(outMin), outMax(outMax) {
}

void ctrl::PIDController::reset() {
	isum = 0;
	last = 0;
}
