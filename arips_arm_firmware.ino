#include "Arduino.h"

/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

#include <Adafruit_MotorShield.h>

#include <Eigen/Dense>

#include <control/VelocityPIDController.h>
#include <control/IndividualGroupController.h>

#include <robot/ArmConfig.h>
#include <robot/JointStateObserver.h>
#include <robot/RobotArmHardware.h>

#include <path/RosMotionManager.h>

#include <utl/Timer.h>

#include <hw/hw.h>

#include <array>

using ros::nh;
using namespace robot;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup() {
	hw::init();

	nh.initNode();
	rosutl::ParameterServer::init();

	nh.advertise(chatter);
}

void loop() {
	RobotModel model;
	JointStateObserver jso[ArmConfig::NUM_JOINTS] = { {0, ADC6, "joint0_observer"} , {1, ADC7, "joint1_observer"}, {2, ADC8, "joint2_observer"}, {3, ADC9, "joint3_observer"}, {4, ADC10, "joint4_observer"} };
	RobotArmHardware armHw(model, { hw::actuator::adafruitV2MotorL1_M1,
									hw::actuator::adafruitV2MotorL1_M2,
									hw::actuator::adafruitV2MotorL1_M3,
									hw::actuator::adafruitV2MotorL1_M4,
									hw::actuator::adafruitV2MotorL0_M1},
								  { jso + 0, jso + 1, jso + 2, jso + 3, jso + 4 });

	ctrl::VelocityPIDController pid[ArmConfig::NUM_JOINTS] =  {
			{"pid_0", -0.7, 0.7},
			{"pid_1", -0.7, 0.7},
			{"pid_2", -0.7, 0.7},
			{"pid_3", -0.7, 0.7},
			{"pid_4", -0.7, 0.7}
	};

	static const float pidParams[ArmConfig::NUM_JOINTS][3] = {
			{0.5, 0.02, 0.0},
			{0.5, 0.02, 0.0},
			{0.5, 0.02, 0.0},
			{0.5, 0.02, 0.0},
			{0.5, 0.02, 0.0}
	};

	for(size_t i = 0; i < ArmConfig::NUM_JOINTS; i++) {
		pid[i].params.P.mValue = pidParams[i][0];
		pid[i].params.I.mValue = pidParams[i][1];
		pid[i].params.D.mValue = pidParams[i][2];
	}

	ctrl::IndividualGroupController<Vec2f, ArmConfig::NUM_JOINTS> controller({pid+0, pid+1, pid+2, pid+3, pid+4});

	path::RosMotionManager motionMan(&controller, &armHw);

	auto handle = SysTickTimer::createTimer(ArmConfig::CONTROL_PERIOD_MS, [&]() {
		str_msg.data = hello;
		chatter.publish(&str_msg);
		motionMan.onControlTick();
	});

	while (true) {
		SysTickTimer::handleTimers();
		nh.spinOnce();
	}
}

