/*
 * VelocityPIDController.cpp
 *
 *  Created on: Aug 20, 2017
 *      Author: jgdo
 */

#include <control/VelocityPIDController.h>

/*
DECL_PARAM_NAME(ctrl::VelocityPIDController::Parameters, float, P, 50, 0, 100);
DECL_PARAM_NAME(ctrl::VelocityPIDController::Parameters, float, I, 0.2, 0, 4);
DECL_PARAM_NAME(ctrl::VelocityPIDController::Parameters, float, D, 1.5f, 0, 500);

template<>
struct UtlParamList<ctrl::VelocityPIDController::Parameters> {
	typedef utl::ParamPack<
	utl::MemberParam<float, ctrl::VelocityPIDController::Parameters, &ctrl::VelocityPIDController::Parameters::P>,
	utl::MemberParam<float, ctrl::VelocityPIDController::Parameters, &ctrl::VelocityPIDController::Parameters::I>,
	utl::MemberParam<float, ctrl::VelocityPIDController::Parameters, &ctrl::VelocityPIDController::Parameters::D>
	> List;
};

*/

namespace ctrl {

VelocityPIDController::VelocityPIDController(const char* name, float outMin, float outMax) :
		params(name), outMin(outMin), outMax(outMax) {
}

void VelocityPIDController::reset() {
	isum = 0;
}

float VelocityPIDController::computeControl(ValueType input, ValueType setpoint) {
	// server.getConfig(params);
	
	float err = setpoint[0] - input[0];
	float derr = setpoint[1] - input[1];
	
	isum += err * params.I.mValue;
	
	if (isum > 0.5)
		isum = .0f;
	else if (isum < -0.5)
		isum = -0.5;
	
	float out = err * params.P.mValue + derr * params.D.mValue + isum;
	
	// anti-windup
	if (out < outMin) {
		out = outMin;
		
		if (isum < 0) {
			float diff = outMin - out; // positive
			isum += diff;
			if (isum > 0) {
				isum = 0;
			}
		}
	} else if (out > outMax) {
		out = outMax;
		
		if (isum > 0) {
			float diff = out - outMax; // positive
			isum -= diff;
			if (isum < 0) {
				isum = 0;
			}
		}
	}
	
	return out;
}

} /* namespace ctrl */
