/*
 * PathHandler.cpp
 *
 *  Created on: Aug 20, 2017
 *      Author: jgdo
 */

#include <path/SingleTargetPathProvider.h>

namespace path {

constexpr float SingleTargetPathProvider::V_MAX; /**< Maximum velocity [rad/s] */
constexpr float SingleTargetPathProvider::A_MAX; /**< Maximum acceleration rate [rad/s²] */

SingleTargetPathProvider::SingleTargetPathProvider() // :
    //	mDefaultSetpoint(defaultSetpoint), mTargetSetpoint(defaultSetpoint), mTimeFinished(float::now()) 
    {
}

SingleTargetPathProvider::~SingleTargetPathProvider() {
}

void SingleTargetPathProvider::setTarget(float now, float target, Vec2f current) {
	float ds = target - current[0];
	
	if (ds * current[1] >= 0) {
		// joint is currently moving in correct direction
		if (std::abs(current[1]) <= V_MAX) {
			// speed is within limits
			generatePathInLimits(now, target, current);
		} else {
			// speed is outside limits, de-accel first
			// print "... outside limits, deaccel first v=%f, max =%f" % (current[0], gMaxV)
			this->mAccelerationRate = current[1] > 0 ? -A_MAX : A_MAX;
			float t_decel_first = (std::abs(current[1]) - V_MAX) / A_MAX;
			// print "t_decel_first = %f" % t_decel_first
			float s_decel_first = 0.5 * this->mAccelerationRate * t_decel_first * t_decel_first + current[1] * t_decel_first;
			this->generatePathInLimits(now + t_decel_first, target,
			    Vec2f(current[0] + s_decel_first, std::max(-V_MAX, std::min(current[1], V_MAX))));
			this->mTimeStart = now;
			this->mStateStart = current;
			this->mAccelerationRate = -this->mAccelerationRate;
		}
	} else {
		// # joint is moving away from target;
		this->mAccelerationRate = ds >= 0 ? A_MAX : -A_MAX;
		float t_decel_first = std::abs(current[1]) / A_MAX;
		float s_decel_first = 0.5 * this->mAccelerationRate * t_decel_first * t_decel_first + current[1] * t_decel_first;
		this->generatePathInLimits(now + t_decel_first, target, Vec2f(current[0] + s_decel_first, 0));
		this->mTimeStart = now;
		this->mStateStart = current;
	}
}

Vec2f SingleTargetPathProvider::getSetpoint(float time, Vec2f currentState) {
	if (time > this->mTimeFinished)
		return Vec2f(this->mPosTarget, 0.0);
	else if (time > this->mTimeStartDecel) {
		float dt = (time - this->mTimeStartDecel);
		return Vec2f(this->mPosStartDeceleration + 0.5 * this->mDecelerationRate * dt * dt + this->mPeakVelocity * dt,
		    this->mPeakVelocity * (1 - dt / this->mDecelerationDuration));
	} else if (time > this->mTimeAccelerationEnd)
		return Vec2f(this->mPosEndAcceleration + (time - this->mTimeAccelerationEnd) * this->mPeakVelocity, this->mPeakVelocity);
	else if (time > this->mTimeStart) {
		float dt = (time - this->mTimeStart);
		return Vec2f(this->mStateStart[0] + 0.5 * this->mAccelerationRate * dt * dt + this->mStateStart[1] * dt, this->mStateStart[1] + this->mAccelerationRate * dt);
	} else
		return Vec2f(this->mStateStart[0], 0);
	
}

void SingleTargetPathProvider::generatePathInLimits(float now, float target, Vec2f current) {
	float ds = target - current[0];
	bool positive = ds > 0;
	this->mAccelerationRate = positive ? A_MAX : -A_MAX;
	this->mPeakVelocity = positive ? V_MAX : -V_MAX;
	
	this->mAccelerationDuration = (this->mPeakVelocity - current[1]) / this->mAccelerationRate;
	this->mDecelerationDuration = this->mPeakVelocity / this->mAccelerationRate;
	
	float t_stop = current[1] / this->mAccelerationRate;
	float s_stop = 0.5 * this->mAccelerationRate * t_stop * t_stop;
	// print s_stop
	
	if (ds * (target - (current[0] + s_stop)) < 0) {
		// will overshoot even if immediately de-accel from now on => \      ________ shape
		//                                                             \----/
		//print "....   overshoot,  \      ____ shape ....\n                    \----/"
		this->generatePositivePart(now + t_stop, target, Vec2f(current[0] + s_stop, 0));
		this->mTimeStart = now;
		this->mStateStart = current;
	} else {
		this->generatePositivePart(now, target, current);
	}
}

void SingleTargetPathProvider::generatePositivePart(float now, float target, Vec2f current) {
	float ds = target - current[0];
	
	bool positive = ds >= 0;
	this->mAccelerationRate = positive ? A_MAX : -A_MAX;
	this->mDecelerationRate = -this->mAccelerationRate;
	this->mPeakVelocity = positive ? V_MAX : -V_MAX;
	
	this->mAccelerationDuration = (this->mPeakVelocity - current[1]) / this->mAccelerationRate;
	float s_accel = 0.5 * this->mAccelerationRate * this->mAccelerationDuration * this->mAccelerationDuration + current[1] * this->mAccelerationDuration;
	this->mDecelerationDuration = this->mPeakVelocity / this->mAccelerationRate;
	float s_decel = 0.5 * this->mAccelerationRate * this->mDecelerationDuration * this->mDecelerationDuration;
	
	// test for different shapes
	if (std::abs(ds) > std::abs(s_accel + s_decel)) {
		// print "....   Using full /---\ shape ...."
		// normal case => /---\ shape
		float s_fullspeed = ds - s_accel - s_decel;
		float t_fullspeed = s_fullspeed / this->mPeakVelocity;
		
		this->mTimeStart = now;
		this->mTimeAccelerationEnd = this->mTimeStart + this->mAccelerationDuration;
		this->mPosEndAcceleration = current[0] + s_accel;
		this->mTimeStartDecel = this->mTimeAccelerationEnd + t_fullspeed;
		this->mPosStartDeceleration = target - s_decel;
		this->mTimeFinished = this->mTimeStartDecel + this->mDecelerationDuration;
		this->mPosTarget = target;
		this->mStateStart = current;
	} else {
		// accelerate and deaccelerate => /\ shape
		// print "....   Using /\ shape ...."
		float t_back = current[1] / this->mAccelerationRate;
		float s_back = 0.5 * this->mAccelerationRate * t_back * t_back;
		
		float ds2 = (ds + s_back) / 2;
		this->mAccelerationDuration = std::sqrt(2 * ds2 / this->mAccelerationRate) - t_back;
		float s_accel = this->mAccelerationDuration * current[1] + 0.5 * this->mAccelerationRate * this->mAccelerationDuration * this->mAccelerationDuration;
		this->mDecelerationDuration = this->mAccelerationDuration + t_back;
		
		this->mPeakVelocity = this->mAccelerationDuration * this->mAccelerationRate + current[1];
		
		this->mTimeStart = now;
		this->mPosEndAcceleration = current[0] + s_accel;
		this->mTimeStartDecel = this->mTimeStart + this->mAccelerationDuration;
		this->mTimeFinished = this->mTimeStartDecel + this->mDecelerationDuration;
		this->mTimeAccelerationEnd = this->mTimeFinished;
		this->mPosStartDeceleration = this->mPosEndAcceleration;
		this->mPosTarget = target;
		this->mStateStart = current;
	}
}

} /* namespace path */
