/*
 * ArmConfig.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jgdo
 */

#ifndef HW_ARMCONFIG_H_
#define HW_ARMCONFIG_H_

#include <cstdint>

namespace ArmConfig {
	static constexpr uint32_t NUM_JOINTS = 1;
	static constexpr uint32_t CONTROL_PERIOD_MS = 10;
	
	static constexpr float JOINT_LIMIT_MIN = 0.1;
	static constexpr float JOINT_LIMIT_MAX = 0.9;
}

#endif /* HW_ARMCONFIG_H_ */
