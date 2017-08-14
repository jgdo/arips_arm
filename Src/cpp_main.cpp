#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>

#include <arips_arm_msgs/control_raw_array.h>
#include <hw/L298.h>

#include <ros.h>
#include <utl/Timer.h>
#include "hw/ControllerHardware.h"
#include "control/PIDController.h"

#include "utl/ROSParameterStoreHandler.h"

using ros::nh;

extern "C" {
int cpp_main(void);

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim1;
}

arips_arm_msgs::control_raw_stamped msg;
ros::Publisher chatter("control_raw", &msg);

int cpp_main() {
	nh.initNode();
	nh.advertise(chatter);
	
	utl::ROSParameterStoreHandler psh;
	
	ctrl::PIDController pid(-1, 1);
	
	auto handle = SysTickTimer::createTimer(10, [&]() {
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		
		auto adc = hw::adc::getAll();
		hw::l298motor0.set(pid.control(adc[1] / 4096.0f, adc[0] / 4096.0f));
		
		msg.stamp = nh.now();
		msg.adc[0] = adc[0];
		msg.adc[1] = adc[1];
		chatter.publish(&msg); 
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
