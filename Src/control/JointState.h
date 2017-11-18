/*
 * JointState.h
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_JOINTSTATE_H_
#define CONTROL_JOINTSTATE_H_

#include <utl/vecdef.h>

namespace ctrl {

struct JointState {
	Vec2f motionState; /**< current (estimated) joint motion state (position, velocity) in [rad, rad/s] */
	float adc_raw;
};

} /* namespace ctrl */



#endif /* CONTROL_JOINTSTATE_H_ */
