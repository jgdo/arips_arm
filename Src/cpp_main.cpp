#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdio.h>

#include <arips_arm_msgs/control_state_array_stamped.h>
#include <hw/L298.h>

#include <ros.h>
#include <utl/Timer.h>
#include "hw/ControllerHardware.h"
#include "control/PIDController.h"

using ros::nh;

extern "C" {
int cpp_main(void);

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim1;
}

arips_arm_msgs::control_state_array_stamped msg;
ros::Publisher chatter("control_state", &msg);

int cpp_main() {
	nh.initNode();
	nh.advertise(chatter);
	
	// utl::ROSParameterStoreHandler psh;
	
	ctrl::PIDController pid(-1, 1);
	msg.data.resize(1);
	
	auto handle = SysTickTimer::createTimer(10, [&]() {
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

		auto adc = hw::adc::getAll();

		//float setpoint = utl::ParameterStore::get<float>(utl::PS_ID_SETPOINT);
		//if(setpoint == 0.0f)
		  float setpoint = adc[0] / 4096.0f;

		  float out = pid.control(adc[1] / 4096.0f, setpoint);
		  hw::l298motor0.set(out);

		  msg.stamp = nh.now();
		  msg.data[0].input_raw = adc[1];
		  msg.data[0].input_pos = adc[1] / 4096.0f;
		  msg.data[0].setpoint_pos = setpoint;
		  msg.data[0].output = out;
		  
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
