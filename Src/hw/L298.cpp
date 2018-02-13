/*
 * L298.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */


#include "L298.h"

// TODO: enter actual pins
hw::L298Motor hw::l298motor0("joint0_motor", JOINT0_IN1_GPIO_Port, JOINT0_IN1_Pin, JOINT0_IN2_GPIO_Port, JOINT0_IN2_Pin, TIM1, TIM1->CCR1);
hw::L298Motor hw::l298motor1("joint1_motor", JOINT1_IN1_GPIO_Port, JOINT1_IN1_Pin, JOINT1_IN2_GPIO_Port, JOINT1_IN2_Pin, TIM1, TIM1->CCR2);
hw::L298Motor hw::l298motor2("joint2_motor", JOINT2_IN1_GPIO_Port, JOINT2_IN1_Pin, JOINT2_IN2_GPIO_Port, JOINT2_IN2_Pin, TIM1, TIM1->CCR3);
hw::L298Motor hw::l298motor3("joint34_left_motor", JOINT34_LEFT_IN1_GPIO_Port, JOINT34_LEFT_IN1_Pin, JOINT34_LEFT_IN2_GPIO_Port, JOINT34_LEFT_IN2_Pin, TIM2, TIM2->CCR1);
hw::L298Motor hw::l298motor4("joint34_right_motor", JOINT34_RIGHT_IN1_GPIO_Port, JOINT34_RIGHT_IN1_Pin, JOINT34_RIGHT_IN2_GPIO_Port, JOINT34_RIGHT_IN2_Pin, TIM2, TIM2->CCR2);
hw::L298Motor hw::l298motor5("gripper_motor", GRIPPER_IN1_GPIO_Port, GRIPPER_IN1_Pin, GRIPPER_IN2_GPIO_Port, GRIPPER_IN2_Pin, TIM2, TIM2->CCR3);
