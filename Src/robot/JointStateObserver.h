/*
 * JointStateObserver.h
 *
 *  Created on: Feb 11, 2018
 *      Author: jgdo
 */

#ifndef ROBOT_JOINTSTATEOBSERVER_H_
#define ROBOT_JOINTSTATEOBSERVER_H_

#include <utl/ParameterServer.h>
#include <hw/ControllerHardware.h>

#include "JointState.h"

namespace robot {

class JointStateObserver {
public:
	JointStateObserver(size_t index, const char* name): 
		mParams(name),
		mAdcIndex(index),
		mLastPos(hw::adc::getAll()[1]), mLastVel(0), mLastMs(hw::clock::getTimeMs()) 
	{
	}
	
	inline JointState observeJointState() {
		auto adc = hw::adc::getAll()[mAdcIndex];
		float pos = adc * mParams.factor.mValue + mParams.offset.mValue;
		
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
	struct Parameters: public utl::ParameterGroup {	
		Parameters(const char* name):
			utl::ParameterGroup(name),
			factor("factor", this, 1.0f),
			offset("offset", this, 0.0f)
		{
		}
		
		utl::FloatParam factor, offset;
	};
	
	Parameters mParams;
	
	size_t mAdcIndex;
	float mLastPos, mLastVel;
	uint32_t mLastMs;
};

} /* namespace robot */


#endif /* ROBOT_JOINTSTATEOBSERVER_H_ */
