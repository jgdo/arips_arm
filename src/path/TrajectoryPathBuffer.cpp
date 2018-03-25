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

bool TrajectoryPathBuffer::setTrajectoryPoint(size_t index, const arips_arm_msgs::TrajectoryPoint& point) {
    if(index >= mTrajectoryBuffer.size()-1)
        return false;

    int offset = (mBufferStart + index) % mTrajectoryBuffer.size();
    mTrajectoryBuffer.at(offset) = point;
    mBufferEnd = (offset+1) % mTrajectoryBuffer.size();
	return true;
}

TrajectoryPathBuffer::PointState TrajectoryPathBuffer::getNextSetpoint(robot::JointMotionStates* setpoint) {
    // printf("%d\n", mRemainingTrajectorySize);
	if (mRemainingTrajectorySize <= 0) {
		return FINISHED;
	}
	if (getCurrentBufferSize()) {
		for(size_t i = 0; i < NUM_JOINTS; i++) {
			// TODO use .at(i)
			setpoint->at(i)[0] = mTrajectoryBuffer.at(mBufferStart).goals[i].position;
			setpoint->at(i)[1] = mTrajectoryBuffer.at(mBufferStart).goals[i].velocity;
		}
		
		mBufferStart = nextIndex(mBufferStart);
		mRemainingTrajectorySize--;
		return VALID;
	} else {
		return EMPTY;
	}
}

} /* namespace path */
