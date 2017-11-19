/*
 * TrajectoryPathProvider.h
 *
 *  Created on: Nov 19, 2017
 *      Author: jgdo
 */

#ifndef PATH_TRAJECTORYPATHBUFFER_H_
#define PATH_TRAJECTORYPATHBUFFER_H_

#include <hw/ArmConfig.h>
#include <utl/vecdef.h>

#include <array>

namespace path {

struct JointPoint {
	float position;
	float velocity;
	float acceleration;
};

struct TrajectoryPoint {
	std::array<JointPoint, ArmConfig::NUM_JOINTS> joints;
};

class TrajectoryPathBuffer {
public:
	static const size_t TRAJECTORY_BUFFER_CAPACITY = 20;
	
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
	 * @param point point to add to trajectory
	 * @return True if point could be added, false if trajectory buffer is full.
	 */
	bool addTrajectoryPoint(const TrajectoryPoint& point);
		
	/**
	 * Get next trajectory setpoint.
	 * 
	 * @param currentState current joint state (position, velocity)
	 * @param point where to store the output
	 * @return point state
	 */
	PointState getNextSetpoint(Vec2f currentState, Vec2f* point);
	
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
	
private:
	std::array<TrajectoryPoint, TRAJECTORY_BUFFER_CAPACITY> mTrajectoryBuffer;
	size_t mBufferStart = 0; // index to next trajectory point to read
	size_t mBufferEnd = 0; // index after last trajectory point (next trajectory point to write)
	
	size_t mRemainingTrajectorySize = 0; // remaining trajectory points until finished (not remaining buffer size!)
	
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