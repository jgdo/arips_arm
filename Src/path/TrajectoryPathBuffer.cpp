/*
 * TrajectoryPathProvider.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: jgdo
 */

#include <path/TrajectoryPathBuffer.h>

namespace path {

TrajectoryPathBuffer::TrajectoryPathBuffer() {
}

TrajectoryPathBuffer::~TrajectoryPathBuffer() {
}

void TrajectoryPathBuffer::newTrajectory(size_t trajectorySize) {
	mBufferEnd = mBufferStart = 0;
	mRemainingTrajectorySize = trajectorySize;
}

bool TrajectoryPathBuffer::addTrajectoryPoint(const TrajectoryPoint& point) {
	uint32_t nextEnd = nextIndex(mBufferEnd);
	if(nextEnd == mBufferStart) {
		return false;
	}
	
	mTrajectoryBuffer[mBufferEnd] = point;
	mBufferEnd = nextEnd;
	return true;
}

TrajectoryPathBuffer::PointState TrajectoryPathBuffer::getNextSetpoint(Vec2f currentState, Vec2f* point) {
	if(mRemainingTrajectorySize <= 0) {
		return FINISHED;
	}	if(getCurrentBufferSize()) {
		point->x() = mTrajectoryBuffer[mBufferStart].joints[0].position;
		point->y() = mTrajectoryBuffer[mBufferStart].joints[0].velocity;
		mBufferStart = nextIndex(mBufferStart);
		mRemainingTrajectorySize--;
		return VALID;
	} else {
		return EMPTY;
	}
}


} /* namespace path */
