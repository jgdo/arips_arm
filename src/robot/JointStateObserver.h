/*
 * JointStateObserver.h
 *
 *  Created on: Feb 11, 2018
 *      Author: jgdo
 */

#ifndef ROBOT_JOINTSTATEOBSERVER_H_
#define ROBOT_JOINTSTATEOBSERVER_H_

#include <rosutil/ParameterServer.h>
#include <hw/hw.h>

#include "JointState.h"

namespace robot {

class JointStateObserver {
public:
	JointStateObserver(size_t jointIndex, int adcIndex, const char* name):
		mParams(name),
		mAdcIndex(adcIndex),
		mLastPos(hw::adc::getChannel(adcIndex)),
		mLastVel(0),
		mLastMs(hw::clock::getMsTick())
	{
		static const float initLimits[6][2] = {
				{-0.0008080, 1775},
				{-0.0011276, 1910},
				{-0.0013046, 2403},
				{-0.0009111, 1988},
				{-0.0013780, 1901},
				{-0.00032, 2550}
		}; 
		
		mParams.factor.mValue = initLimits[jointIndex][0];
		mParams.offset.mValue = initLimits[jointIndex][1];
	}
	
	inline JointState observeJointState() {
		auto adc = hw::adc::getChannel(mAdcIndex);
		float pos = (adc - mParams.offset.mValue) * mParams.factor.mValue;
		
		uint32_t now = hw::clock::getMsTick();
		uint32_t dt = now - mLastMs;
		
		if(dt > 5) {
			mLastVel = (pos - mLastPos) / (dt * 0.001f);
			mLastPos = pos;
			mLastMs = now;
		} 
		
		return JointState { Vec2f(pos, mLastVel) };
	}
	
private:	
	struct Parameters: public rosutl::ParameterGroup {
		Parameters(const char* name):
			rosutl::ParameterGroup(name),
			factor("factor", this, 1.0f),
			offset("offset", this, 0.0f)
		{
		}
		
		rosutl::FloatParam factor, offset;
	};
	
	Parameters mParams;
	
	size_t mAdcIndex;
	float mLastPos, mLastVel;
	uint32_t mLastMs;
};

} /* namespace robot */


#endif /* ROBOT_JOINTSTATEOBSERVER_H_ */
