#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>

#include <std_msgs/String.h>

#include <ros.h>

extern "C" {
	int cpp_main(void);
	
	extern ADC_HandleTypeDef hadc1;

	extern TIM_HandleTypeDef htim1;
}

ros::NodeHandle nh;

void setMotorPWM(float percent) {	
	if (percent > 0.01) {
		HAL_GPIO_WritePin(IN_1_GPIO_Port, IN_1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IN_2_GPIO_Port, IN_2_Pin, GPIO_PIN_RESET);
		htim1.Instance->CCR1 = (uint16_t) (percent * (htim1.Init.Period-1));
	} else if (percent < -0.01) {
		HAL_GPIO_WritePin(IN_1_GPIO_Port, IN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IN_2_GPIO_Port, IN_2_Pin, GPIO_PIN_SET);
		htim1.Instance->CCR1 = (uint16_t) -(percent * (htim1.Init.Period-1));
	} else { // speed is 0
		HAL_GPIO_WritePin(IN_2_GPIO_Port, IN_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IN_2_GPIO_Port, IN_2_Pin, GPIO_PIN_RESET);
		TIM1->CCR1 = 0;
	}
}

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

int cpp_main() {
	nh.initNode();
	nh.advertise(chatter);
	
	while (1)
	{
		if(HAL_ADC_PollForConversion(&hadc1, 1000) == HAL_OK) {
			int value = HAL_ADC_GetValue(&hadc1);
			printf("adc: %d\n", value);
			
			if(value > 2100)
				setMotorPWM(-0.3);
			else if(value < 1900)
				setMotorPWM(0.3);
			else
				setMotorPWM(0);
		}
		
		str_msg.data = hello;
		chatter.publish( &str_msg );
		nh.spinOnce();

		HAL_Delay(1000);
	}
	  
	return 0;
}
