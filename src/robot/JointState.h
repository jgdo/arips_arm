/*
 * JointState.h
 *
 *  Created on: Sep 22, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_JOINTSTATE_H_
#define CONTROL_JOINTSTATE_H_

#include <utl/vecdef.h>

#include "ArmConfig.h"

namespace robot {

struct JointState {
	Vec2f motionState; /**< current (estimated) joint motion state (position, velocity) in [rad, rad/s] */
	// float rawPosition; /**< raw position value, usually from corresponding adc, unit undefined */
};

typedef std::array<Vec2f, ArmConfig::NUM_ARM_JOINTS> JointMotionStatesArm;
typedef std::array<Vec2f, ArmConfig::NUM_ALL_JOINTS> JointMotionStatesAll;

} /* namespace robot */



#endif /* CONTROL_JOINTSTATE_H_ */
