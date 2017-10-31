/*
 * ControllerHardware.h
 *
 *  Created on: Aug 11, 2017
 *      Author: jgdo
 */

#ifndef CONTROLLERHARDWARE_H_
#define CONTROLLERHARDWARE_H_

#include <stm32f1xx_hal.h>

#include <cstddef>
#include <array>

#include "main.h"
#include "Actuator.hpp"

#include "stm32f1xx_hal.h"

// Controller Hardware
namespace hw {

namespace adc {

static constexpr size_t NUM_CHANNELS = ADC_CHANNELS_IN_USE;

inline std::array<float, NUM_CHANNELS> getAll() {
	std::array<float, NUM_CHANNELS> adc;
	__disable_irq();
	for (size_t i = 0; i < NUM_CHANNELS; i++) {
		adc[i] = gAdcCurrentValue[i];
	}
	__enable_irq();
	
	return adc;
}

inline int get(size_t channel) {
	if(channel >= NUM_CHANNELS)
		return -1;
	
	__disable_irq();
	int adc = gAdcCurrentValue[channel];
	__enable_irq();
	
	return adc;
}

} // namespace adc

extern std::array<Actuator*, 1> allMotors;

namespace clock {

inline uint32_t getTimeMs() {
	return HAL_GetTick();
}

} // namespace clock 

} // namespace hw 

#endif /* CONTROLLERHARDWARE_H_ */
