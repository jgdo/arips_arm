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
	
	RobotModel model;
	JointStateObserver jso[ArmConfig::NUM_JOINTS] = { {0, "joint0_observer"} , {1, "joint1_observer"}, {2, "joint2_observer"}, {3, "joint3_observer"}, {4, "joint4_observer"} };
	RobotArmHardware armHw(model, 
												 { &hw::l298motor0, &hw::l298motor1, &hw::l298motor2, &hw::l298motor3, &hw::l298motor4 },
												 { jso + 0, jso + 1, jso + 2, jso + 3, jso + 4 });
	
	ctrl::VelocityPIDController pid[ArmConfig::NUM_JOINTS] =  { 
			{"pid_0", -0.7, 0.7},
			{"pid_1", -0.7, 0.7},
			{"pid_2", -0.7, 0.7},
			{"pid_3", -0.7, 0.7},
			{"pid_4", -0.7, 0.7}
	};
	
	static const float pidParams[ArmConfig::NUM_JOINTS][3] = {
			{1.0, 0.06, 0.2},
			{1.5, 0.05, 0.5},
			{1.0, 0.05, 0.4},
			{1.0, 0.02, 0.15},
			{1.0, 0.02, 0.1}
	};
	
	for(size_t i = 0; i < ArmConfig::NUM_JOINTS; i++) {
		pid[i].params.P.mValue = pidParams[i][0];
		pid[i].params.I.mValue = pidParams[i][1];
		pid[i].params.D.mValue = pidParams[i][2];
	}
	
	ctrl::IndividualGroupController<Vec2f, ArmConfig::NUM_JOINTS> controller({pid+0, pid+1, pid+2, pid+3, pid+4});
	
	path::RosMotionManager motionMan(&controller, &armHw);
	
	auto handle = SysTickTimer::createTimer(ArmConfig::CONTROL_PERIOD_MS, [&]() {
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		motionMan.onControlTick();
		resetWatchdog();
	});
	
	// int i = 0;
	while (1) {
		SysTickTimer::handleTimers();
		nh.spinOnce();
		
		// printf("a %d\n", i++);
	}
	
	return 0;
}
