/*
 * RosMotionManager.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: jgdo
 */

#include <path/RosMotionManager.h>


namespace path {

RosMotionManager::RosMotionManager(ctrl::Controller<Eigen::Vector2f>* controller, hw::Actuator* actuator, JointStateObserver* jso):
  mMotionManager(controller, actuator, jso),
	mMotionCmdSub ("motion_command", &RosMotionManager::onMotionCommandCb, this),
	mTrajBuffSub("traj_buffer_command", &RosMotionManager::onTrajectoryBuffCb, this),
	mMotionStatePub("motion_state", &mMotionStateMsg) {
	
	ros::nh.advertise(mMotionStatePub);
	ros::nh.subscribe(mMotionCmdSub);
	ros::nh.subscribe(mTrajBuffSub);
}

void RosMotionManager::onControlTick() {
	mMotionStateMsg.stamp = ros::Time::now();
	mMotionStateMsg.mode = mMotionManager.getState();
	mMotionStateMsg.jointStates[0] = mMotionManager.onControlTick();
	mMotionStateMsg.trajState.bufferCapacity = TrajectoryPathBuffer::TRAJECTORY_BUFFER_CAPACITY;
	mMotionStateMsg.trajState.controlCycleCount = mMotionManager.getControlCycleCount();
	mMotionStateMsg.trajState.numPointsInBuffer = mMotionManager.getTrajectoryBuffer().getCurrentBufferSize();
	
	mMotionStatePub.publish(&mMotionStateMsg);
}

void RosMotionManager::onMotionCommandCb(const arips_arm_msgs::MotionCommand& msg) {
	using arips_arm_msgs::MotionCommand;
	
	if(msg.command == MotionCommand::CMD_SINGLE_TARGET) {
		mMotionManager.setNewSingleGoal(msg.st_position);
	} else if(msg.command == MotionCommand::CMD_START_TRAJECTORY) {
		mMotionManager.startFollowingTrajectory();
	} else if(msg.command == MotionCommand::CMD_STOP) {
		mMotionManager.stop();
	} else if(msg.command == MotionCommand::CMD_RELEASE) {
		mMotionManager.release();
	}
}

void RosMotionManager::onTrajectoryBuffCb(const arips_arm_msgs::TrajectoryBufferCommand& msg) {
	TrajectoryPathBuffer& buf = mMotionManager.getTrajectoryBuffer();
	if(msg.start_index > mMotionManager.getControlCycleCount()) {
		return; // error: skipped points
	} else {
		size_t start_index = 0;
		
		if(msg.start_index == 0) {
			start_index = 0;
			buf.newTrajectory(msg.size);
		} else {
			start_index = mMotionManager.getControlCycleCount() - msg.start_index;
		}
		
		for(size_t i = start_index; i < std::min<size_t>(msg.size, msg.traj_points.size()); i++) {
			::path::TrajectoryPoint point;
			auto const& origPoint = msg.traj_points.at(i);
			static_assert(ArmConfig::NUM_JOINTS == std::tuple_size<arips_arm_msgs::TrajectoryPoint::_positions_type>::value);
			static_assert(ArmConfig::NUM_JOINTS == std::tuple_size<arips_arm_msgs::TrajectoryPoint::_velocities_type>::value);
			static_assert(ArmConfig::NUM_JOINTS == std::tuple_size<arips_arm_msgs::TrajectoryPoint::_accelerations_type>::value);
			
			for(size_t j = 0; j < ArmConfig::NUM_JOINTS; j++) {
				point.joints.at(j).position = origPoint.positions.at(j);
				point.joints.at(j).velocity = origPoint.velocities.at(j);
				point.joints.at(j).acceleration = origPoint.accelerations.at(j);
			}
			
			if(!buf.addTrajectoryPoint(point)) {
				break; // buffer is full
			}
		}
	}
}


} /* namespace path */

