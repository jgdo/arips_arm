/*
 * hw.h
 *
 *  Created on: Mar 11, 2018
 *      Author: jgdo
 */

#ifndef HW_HW_H_
#define HW_HW_H_

#include "Actuator.hpp"

#include <cstdint>
#include <cstddef>

namespace hw {

void init();

namespace actuator {
	extern Actuator* adafruitV2MotorL0_M1;
	extern Actuator* adafruitV2MotorL0_M2;
	extern Actuator* adafruitV2MotorL0_M3;
	extern Actuator* adafruitV2MotorL0_M4;
	extern Actuator* adafruitV2MotorL1_M1;
	extern Actuator* adafruitV2MotorL1_M2;
	extern Actuator* adafruitV2MotorL1_M3;
	extern Actuator* adafruitV2MotorL1_M4;
}

namespace adc {

float getChannel(size_t channel);

}

namespace clock {

uint32_t getMsTick();

} // namespace clock

} /* namespace hw */

#endif /* HW_HW_H_ */
