/*
 * PIDController.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#include <cmath>

#include <control/PIDController.h>

DECL_PARAM_NAME(ctrl::PIDParameters, float, P, 50, 0, 100);
DECL_PARAM_NAME(ctrl::PIDParameters, float, I, 0.3, 0, 4);
DECL_PARAM_NAME(ctrl::PIDParameters, float, D, 1.5f, 0, 5);

template<>
struct UtlParamList<ctrl::PIDParameters> {
    typedef utl::ParamPack<
        utl::MemberParam<float, ctrl::PIDParameters, &ctrl::PIDParameters::P>,
        utl::MemberParam<float, ctrl::PIDParameters, &ctrl::PIDParameters::I>,
        utl::MemberParam<float, ctrl::PIDParameters, &ctrl::PIDParameters::D>
    > List;
};

namespace ctrl {

float PIDController::control(ValueType input, ValueType setpoint) {	
	server.getConfig(params);
	
	float err = setpoint[0]-input[0];
	
	isum += err *params.I;

	if(isum > 0.5)
		isum = .0f;
	else if(isum < -0.5)
		isum = -0.5;
	
	float out = err*params.P + isum - input[1] * params.D;
	
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

ctrl::PIDController::PIDController(float outMin, float outMax): server("pid"), outMin(outMin), outMax(outMax) {
}

void ctrl::PIDController::reset() {
	isum = 0;
}
