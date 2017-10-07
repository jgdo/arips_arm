/*
 * PathHandler.h
 *
 *  Created on: Aug 20, 2017
 *      Author: jgdo
 */

#ifndef PATH_SINGLETARGETPATHPROVIDER_H_
#define PATH_SINGLETARGETPATHPROVIDER_H_

#include <control/JointState.h>
#include <utl/vecdef.h>
#include <ros.h>

namespace path {

class SingleTargetPathProvider {
public:
	SingleTargetPathProvider(float defaultSetpoint);
	~SingleTargetPathProvider();
	
	/**
	 * @brief Override current target with given single target position
	 */
	void setTarget(float now, float target_pos, Vec2f currentState);
	
	Vec2f getSetpoint(float currentTime, Vec2f currentState);
	
private:
	static const float V_MAX = 0.1; /**< Maximum velocity [rad/s] */
	static const float A_MAX = 0.1; /**< Maximum acceleration rate [rad/s²] */
	
	float mAccelerationRate = 0.0; /**< acceleration rate [rad/s²] to use during positive acceleration phase */
	float mDecelerationRate = 0.0; /**< deceleration rate [rad/s²] to use during deceleration phase */
	float mPeakVelocity = 0.0; /**< maximum velocity [rad/s] during the movement */
	float mAccelerationDuration = 0.0; /**< duration [s] of acceleration phase */
	float mDecelerationDuration = 0.0; /**< duration [s] of deceleration phase */
	float mPosEndAcceleration = 0.0; /**< position [rad] then acceleration phase is finished and velocity is at mPeakVelocity */
	float mPosStartDeceleration = 0.0; /**< position [rad] when to begin decelerate from mPeakVelocity */
	float mTimeStart = 0.0; /**< time [s] of movement start */
	float mTimeAccelerationEnd = 0.0; /**< time [s] to stop acceleration when peak velocity is reached */
	float mTimeStartDecel = 0.0; /**< time [s] then to begin decelerate */
	float mTimeFinished = 0.0; /**< time [s] when the movement has finished */
	Vec2f mStateStart = 0.0; /**< movement start position [rad, rad/s] */
	float mPosTarget = 0.0; /**< movement target end position [s]. Target velocity is always 0 */
	
	void generatePathInLimits(float now, float target, Vec2f current);
	
	void generatePositivePart(float now, float target, Vec2f current);
};

} /* namespace path */

#endif /* PATH_SINGLETARGETPATHPROVIDER_H_ */
