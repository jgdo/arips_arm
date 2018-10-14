/*
 * TrajectoryPathProvider.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jgdo
 */

#ifndef PATH_TRAJECTORYPATHBUFFER_H_
#define PATH_TRAJECTORYPATHBUFFER_H_

#include <robot/JointState.h>
#include <utl/vecdef.h>

#include <array>

#include <arips_arm_msgs/TrajectoryPoint.h>

namespace path {

class TrajectoryPathBuffer {
public:
	static const size_t TRAJECTORY_BUFFER_CAPACITY = 64;
	
	enum PointState {
		VALID, // point is valid
		EMPTY, // buffer empty, waiting
		FINISHED, // trajectory finished
	};
	
	TrajectoryPathBuffer();
	~TrajectoryPathBuffer();
	
	/**
	 * clear trajectory buffer, reset control step counter
	 * 
	 * @param trajectorySize size of trajectory
	 */
	void newTrajectory(size_t trajectorySize);
	
	/**
	 * Add a point to end of trajectory buffer
	 * 
	 * @param index index offset from current trajectory point
	 * @param point point to add to trajectory
	 * @return True if point could be set, false if index is outside trajectory buffer limit.
	 */
	bool setTrajectoryPoint(size_t index, const arips_arm_msgs::TrajectoryPoint& point);
		
	/**
	 * Get next trajectory setpoint.
	 * 
	 * @param point where to store the output
	 * @param timeFromStart_ms current trajectory execution time
	 * @return point state
	 */
	PointState getNextSetpoint(robot::JointMotionStatesArm* setpoint, uint32_t timeFromStart_ms);
	
	/**
	 * @return remaining trajectory buffer capacity
	 */
	size_t remainingBufferCapacity() const {
		return TRAJECTORY_BUFFER_CAPACITY - getCurrentBufferSize() - 1;
	}
	
	/**
	 * @return number of points in trajectory buffer
	 */
	inline size_t getCurrentBufferSize() const {
		int32_t size = (int32_t)mBufferEnd - (int32_t)mBufferStart;
			if(size < 0) {
				size += TRAJECTORY_BUFFER_CAPACITY;
			}
			return size;
	}
	
	/**
	 * Get the absolute index of the last passed trajectory point
	 */
	inline size_t getLastTrajectoryIndex() const {
	    return mLastPassedPointIndex;
	}

private:
	std::array<arips_arm_msgs::TrajectoryPoint, TRAJECTORY_BUFFER_CAPACITY> mTrajectoryBuffer;
	size_t mBufferStart = 0; // index to next trajectory point to read
	size_t mBufferEnd = 0; // index after last trajectory point (next trajectory point to write)
	
	size_t mTotalTrajectorySize = 0; // number of points in trajectory
	size_t mLastPassedPointIndex = 0; // absolute index of last passed point (not index in mTrajectoryBuffer !!!)
	
	inline uint32_t nextIndex(uint32_t index) const {
		index++;
		if(index >= mTrajectoryBuffer.size()) {
			index = 0;
		}
		return index;
	}
};

} /* namespace path */

#endif /* PATH_TRAJECTORYPATHBUFFER_H_ */
