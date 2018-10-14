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
    static constexpr uint32_t NUM_ARM_JOINTS = 5;
	static constexpr uint32_t NUM_ALL_JOINTS = NUM_ARM_JOINTS+1;
	static constexpr uint32_t GRIPPER_INDEX = NUM_ARM_JOINTS;

	static constexpr uint32_t CONTROL_PERIOD_MS = 8;
	static constexpr float CONTROL_PERIOD_S = CONTROL_PERIOD_MS * 0.001F;

	static constexpr uint32_t JOINT_OBSERVE_PERIOD_MS = 4;
	static constexpr float JOINT_OBSERVE_PERIOS_S = JOINT_OBSERVE_PERIOD_MS * 0.001F;
}

typedef ctrl::GroupController<Vec2f, ArmConfig::NUM_ALL_JOINTS> RobotArmController;

}

#endif /* HW_ARMCONFIG_H_ */
