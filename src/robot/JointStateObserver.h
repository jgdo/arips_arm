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

#include <utl/Kalman.h>

namespace robot {

class JointStateObserver {
public:
	JointStateObserver(size_t jointIndex, int adcIndex, const char* name):
		mParams(name),
		mAdcIndex(adcIndex),
		mLastMs(hw::clock::getMsTick())
	{
		static const float initLimits[6][2] = {
				{-0.0008056, 1775},
				{-0.0011894, 1954},
				{-0.0012800, 2457},
				{-0.0009111, 1988},
				{-0.0013780, 1901},
				{-0.00032, 2550}
		}; 
		
		mParams.factor.mValue = initLimits[jointIndex][0];
		mParams.offset.mValue = initLimits[jointIndex][1];

		mKalmanFilter.F << 1.0F, ArmConfig::JOINT_OBSERVE_PERIOS_S,
		                    0.0F, 0.99;
		mKalmanFilter.Q << ArmConfig::JOINT_OBSERVE_PERIOS_S*0.02F, 0.0F,
		                    0.0F, ArmConfig::JOINT_OBSERVE_PERIOS_S*3;
		mKalmanFilter.B << 0.0F, 0.0F;
		mKalmanFilter.H << 1.0F, 0.0F;
		mKalmanFilter.R << 0.0002F;
	}
	
	inline JointState observeJointState(float lastTorque) {
		uint32_t now = hw::clock::getMsTick();
		uint32_t dt = now - mLastMs;
		
		if(dt > 0) {

		    auto adc = hw::adc::getChannel(mAdcIndex);
		    float pos = (adc - mParams.offset.mValue) * mParams.factor.mValue;


		    Eigen::Matrix<float, 1, 1> obs;
		    obs[0] = pos;
		    Eigen::Matrix<float, 1, 1> u;
		    u[0] = lastTorque;
		    mKalmanFilter.update(obs, u);
			mLastMs = now;
		} 
		
		return JointState { mKalmanFilter.x };
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
	uint32_t mLastMs;

	KalmanFilter<2, 1, 1> mKalmanFilter;
};

} /* namespace robot */


#endif /* ROBOT_JOINTSTATEOBSERVER_H_ */
