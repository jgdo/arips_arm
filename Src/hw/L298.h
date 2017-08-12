/*
 * L298.h
 *
 *  Created on: Jun 25, 2017
 *      Author: jgdo
 */

#ifndef HW_L298_H_
#define HW_L298_H_

#include <hw/Actuator.hpp>
#include <stm32f1xx_hal.h>

namespace hw {

class L298Motor: public Actuator {
public:
	L298Motor(const char* name, GPIO_TypeDef*in1, uint16_t pin1, GPIO_TypeDef* in2, uint16_t pin2, TIM_TypeDef* tim, __IO uint32_t& ccr): 
		mIn1Port(in1), mIn2Port(in2), mTimer(tim), mCCR(ccr), mName(name), mIn1Pin(pin1), mIn2Pin(pin2) {
	}
	
	virtual ~L298Motor() {}
	
	virtual void set(float value) {
		if (value > 0.01) {
				HAL_GPIO_WritePin(mIn1Port, mIn1Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(mIn2Port, mIn2Pin, GPIO_PIN_RESET);
				mCCR = (uint16_t) (value * (mTimer->ARR-1));
			} else if (value < -0.01) {
				HAL_GPIO_WritePin(mIn1Port, mIn1Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(mIn2Port, mIn2Pin, GPIO_PIN_SET);
				mCCR = (uint16_t) -(value * (mTimer->ARR-1));
			} else { // speed is 0
				HAL_GPIO_WritePin(mIn1Port, mIn1Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(mIn2Port, mIn2Pin, GPIO_PIN_RESET);
				mCCR= 0;
			}
	}
	
	virtual const char* name() const {
		return mName;
	}

private:
	GPIO_TypeDef * const mIn1Port;
	GPIO_TypeDef * const mIn2Port;
	
	TIM_TypeDef* const mTimer;
	__IO uint32_t& mCCR;
	
	const char* const mName;
	
	const uint16_t mIn1Pin, mIn2Pin;
	
};

extern L298Motor l298motor0; 

} // namespace hw 


#endif /* HW_L298_H_ */
