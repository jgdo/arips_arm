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
	mTotalTrajectorySize = trajectorySize;
	mLastPassedPointIndex = 0;
}

bool TrajectoryPathBuffer::setTrajectoryPoint(size_t index, const arips_arm_msgs::TrajectoryPoint& point) {
    if(index >= mTrajectoryBuffer.size()-1)
        return false;

    int offset = (mBufferStart + index) % mTrajectoryBuffer.size();
    mTrajectoryBuffer.at(offset) = point;
    mBufferEnd = nextIndex(offset);
	return true;
}

TrajectoryPathBuffer::PointState TrajectoryPathBuffer::getNextSetpoint(robot::JointMotionStatesArm* setpoint, uint32_t timeFromStart_ms) {
    auto bufSize = getCurrentBufferSize();
    if(bufSize == 0 || timeFromStart_ms < mTrajectoryBuffer.at(mBufferStart).timeFromStart_ms) {
        return EMPTY;
    }

    if(bufSize > 1) {
        auto nextStart = nextIndex(mBufferStart);
        if(timeFromStart_ms >= mTrajectoryBuffer.at(nextStart).timeFromStart_ms) {
            mBufferStart = nextStart;
            mLastPassedPointIndex++;
        }
    }


    for(size_t i = 0; i < setpoint->size(); i++) {
        // TODO use .at(i)
        setpoint->at(i)[0] = mTrajectoryBuffer.at(mBufferStart).goals[i].position;
        setpoint->at(i)[1] = mTrajectoryBuffer.at(mBufferStart).goals[i].velocity;
    }

    if(mLastPassedPointIndex == mTotalTrajectorySize-1) {
        return FINISHED;
    } else {
        return VALID;
    }

}

} /* namespace path */
