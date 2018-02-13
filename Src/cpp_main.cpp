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
#include <robot/JointStateObserver.h>

#include <control/IndividualGroupController.h>
#include <robot/RobotArmHardware.h>

using ros::nh;
using namespace robot;

extern "C" {
int cpp_main(void);

extern ADC_HandleTypeDef hadc1;

extern TIM_HandleTypeDef htim1;
}

int cpp_main() {
	nh.initNode();
	utl::ParameterServer::init();
	
	// TODO observers for correct joint
	JointStateObserver jso[5] = { 0, 1, 2, 3, 4 };
	RobotArmHardware armHw( { &hw::l298motor0, &hw::l298motor1, &hw::l298motor2, &hw::l298motor3, &hw::l298motor4 },
			{ jso + 0, jso + 1, jso + 2, jso + 3, jso + 4 });
	
	ctrl::VelocityPIDController pid0(-1, 1), pid1(-1, 1), pid2(-1, 1), pid3(-1, 1), pid4(-1, 1);
	ctrl::IndividualGroupController<Vec2f, ArmConfig::NUM_JOINTS> controller( { &pid0, &pid1, &pid2, &pid3, &pid4 });
	
	path::RosMotionManager motionMan(&controller, &armHw);
	
	auto handle = SysTickTimer::createTimer(ArmConfig::CONTROL_PERIOD_MS, [&]() {
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		motionMan.onControlTick();
	});
	
	int i = 0;
	while (1) {
		SysTickTimer::handleTimers();
		nh.spinOnce();
		
		// printf("a %d\n", i++);
	}
	
	return 0;
}
