/*
 * L298.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */


#include "L298.h"

hw::L298Motor hw::l298motor0("l298motor0", IN_1_GPIO_Port, IN_1_Pin, IN_2_GPIO_Port, IN_2_Pin, TIM1, TIM1->CCR1);
