#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>

#include <hw/L298.h>

#include <ros.h>
#include <utl/Timer.h>
#include "hw/ControllerHardware.h"
#include "control/VelocityPIDController.h"
#include <control/PIDController.h>
#include <path/RosMotionManager.h>
#include <utl/ParameterServer.h>

using ros::nh;

extern "C" {
int cpp_main(void);

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim1;
}

int cpp_main() {
	nh.initNode();
	utl::ParameterServer::init();
	
	ctrl::VelocityPIDController pid(-1, 1);
	path::JointStateObserver jso;
	path::RosMotionManager motionMan(&pid, &hw::l298motor0, &jso);
	
	auto handle = SysTickTimer::createTimer(10, [&]() {
		
		
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

		/*
		auto adc = hw::adc::getAll();

		//float setpoint = utl::ParameterStore::get<float>(utl::PS_ID_SETPOINT);
		//if(setpoint == 0.0f)
		  float setpoint = adc[0] / 4096.0f;

		  float out = pid.control(adc[1] / 4096.0f, setpoint);
		  hw::l298motor0.set(out);
		  
		  */
		
		motionMan.onControlTick();
		
		

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
