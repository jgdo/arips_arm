/*
 * TrajectoryPathProvider.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: jgdo
 */

#include <path/TrajectoryPathBuffer.h>

using namespace robot::ArmConfig;

namespace path {

TrajectoryPathBuffer::TrajectoryPathBuffer() {
}

TrajectoryPathBuffer::~TrajectoryPathBuffer() {
}

void TrajectoryPathBuffer::newTrajectory(size_t trajectorySize) {
	mBufferEnd = mBufferStart = 0;
	mRemainingTrajectorySize = trajectorySize;
}

bool TrajectoryPathBuffer::addTrajectoryPoint(const arips_arm_msgs::TrajectoryPoint& point) {
	uint32_t nextEnd = nextIndex(mBufferEnd);
	if (nextEnd == mBufferStart) {
		return false;
	}
	
	mTrajectoryBuffer[mBufferEnd] = point;
	mBufferEnd = nextEnd;
	return true;
}

TrajectoryPathBuffer::PointState TrajectoryPathBuffer::getNextSetpoint(robot::JointMotionStates* setpoint) {
	if (mRemainingTrajectorySize <= 0) {
		return FINISHED;
	}
	if (getCurrentBufferSize()) {
		for(size_t i = 0; i < NUM_JOINTS; i++) {
			setpoint->at(i)[0] = mTrajectoryBuffer[mBufferStart].goals.at(i).position;
			setpoint->at(i)[1] = mTrajectoryBuffer[mBufferStart].goals.at(i).velocity;
		}
		
		mBufferStart = nextIndex(mBufferStart);
		mRemainingTrajectorySize--;
		return VALID;
	} else {
		return EMPTY;
	}
}

} /* namespace path */
