/*
 * ArmConfig.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jgdo
 */

#ifndef HW_ARMCONFIG_H_
#define HW_ARMCONFIG_H_

#include <cstdint>

#include <utl/vecdef.h>

#include <control/GroupController.h>

namespace robot {

namespace ArmConfig {
	static constexpr uint32_t NUM_JOINTS = 5;
	static constexpr uint32_t CONTROL_PERIOD_MS = 10;
	static constexpr float CONTROL_PERIOD_S = CONTROL_PERIOD_MS * 0.001F;
}

typedef ctrl::GroupController<Vec2f, ArmConfig::NUM_JOINTS> RobotArmController;

}

#endif /* HW_ARMCONFIG_H_ */
