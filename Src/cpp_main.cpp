#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>

#include <arips_arm_msgs/control_raw_array.h>

#include <ros.h>
#include <utl/Timer.h>
#include <control/L298.h>

extern "C" {
int cpp_main(void);

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim1;
}

L298Motor motor("motor_1", IN_1_GPIO_Port, IN_1_Pin, IN_2_GPIO_Port, IN_2_Pin, TIM1, TIM1->CCR1);

ros::NodeHandle nh;

arips_arm_msgs::control_raw_array msg;
ros::Publisher chatter("control_raw", &msg);


template<class fdf>
struct C {
	void set() {
		// HAL_GPIO_WritePin(T, IN_2_Pin, GPIO_PIN_RESET);
	}
};

int cpp_main() {
	nh.initNode();
	nh.advertise(chatter);
	
	int dataCounter = 0;
	
	
	auto handle = SysTickTimer::createTimer(100, [&]() {
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		
		if(HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
			int value = HAL_ADC_GetValue(&hadc1);
			
			if(value > 2100)
				motor.set(-0.3);
			else if(value < 1900)
				motor.set(0.3);
			else
				motor.set(0);
			
			msg.data[dataCounter].stamp = nh.now();
			msg.data[dataCounter].adc[0] = value;
			dataCounter++;
			if(dataCounter == sizeof(msg.data)/sizeof(*msg.data)) {
				dataCounter = 0;
				chatter.publish(&msg);
			}
		}
	});
	
	while (1) {
		SysTickTimer::handleTimers();
		nh.spinOnce();
		
//		if(HAL_ADC_PollForConversion(&hadc1, 1000) == HAL_OK) {
//			int value = HAL_ADC_GetValue(&hadc1);
//			printf("adc: %d\n", value);
//			
//			if(value > 2100)
//				setMotorPWM(-0.3);
//			else if(value < 1900)
//				setMotorPWM(0.3);
//			else
//				setMotorPWM(0);
//		}
		
	}
	
	return 0;
}
