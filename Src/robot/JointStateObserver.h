/*
 * JointStateObserver.h
 *
 *  Created on: Feb 11, 2018
 *      Author: jgdo
 */

#ifndef ROBOT_JOINTSTATEOBSERVER_H_
#define ROBOT_JOINTSTATEOBSERVER_H_

#include <hw/ControllerHardware.h>

#include "JointState.h"

namespace robot {

class JointStateObserver {
public:
	JointStateObserver(): mLastPos(hw::adc::getAll()[1]), mLastVel(0), mLastMs(hw::clock::getTimeMs()) {
	}
	
	inline JointState observeJointState() {
		auto adc = hw::adc::getAll()[1];
		float pos = adc / 4096.0f;
		
		uint32_t now = hw::clock::getTimeMs();
		uint32_t dt = now - mLastMs;
		
		if(dt > 5) {
			mLastVel = (pos - mLastPos) / (dt * 0.001f);
			mLastPos = pos;
			mLastMs = now;
		} 
		
		return JointState { Vec2f(pos, mLastVel), adc };
	}
	
private:	
	float mLastPos, mLastVel;
	uint32_t mLastMs;
};

} /* namespace robot */


#endif /* ROBOT_JOINTSTATEOBSERVER_H_ */
