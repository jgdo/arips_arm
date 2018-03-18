/*
 * RobotHardware.h
 *
 *  Created on: Mar 11, 2018
 *      Author: jgdo
 */

#ifndef ROSUTIL_ROBOTROSHARDWARE_H_
#define ROSUTIL_ROBOTROSHARDWARE_H_

#include <Arduino.h>

namespace rosutl {

class RobotRosHardware {
public:
	void init() {
		SerialUSB.begin(2000000);
	}

	int read() {
		return SerialUSB.read();
	}
	;

	void write(uint8_t* data, int length) {
		SerialUSB.write(data, length);
	}

	unsigned long time() {
		return millis();
	}
};

}

#endif /* ROSUTIL_ROBOTROSHARDWARE_H_ */
