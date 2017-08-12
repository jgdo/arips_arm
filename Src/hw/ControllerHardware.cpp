/*
 * ControllerHardware.cpp
 *
 *  Created on: Aug 11, 2017
 *      Author: jgdo
 */

#include "ControllerHardware.h"

#include "L298.h"

std::array<hw::Actuator*, 1> hw::allMotors = { &l298motor0 };
