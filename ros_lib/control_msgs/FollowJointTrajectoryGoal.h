#ifndef _ROS_control_msgs_FollowJointTrajectoryGoal_h
#define _ROS_control_msgs_FollowJointTrajectoryGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "control_msgs/JointTolerance.h"
#include "ros/duration.h"

namespace control_msgs
{

  class FollowJointTrajectoryGoal : public ros::Msg
  {
    public:
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;
      std::vector<control_msgs::JointTolerance> path_tolerance;
      std::vector<control_msgs::JointTolerance> goal_tolerance;
      typedef ros::Duration _goal_time_tolerance_type;
      _goal_time_tolerance_type goal_time_tolerance;

    FollowJointTrajectoryGoal():
      trajectory(),
      path_tolerance(),
      goal_tolerance(),
      goal_time_tolerance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->path_tolerance.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_tolerance.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->path_tolerance.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->path_tolerance.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < path_tolerance.size(); i++){
      offset += this->path_tolerance[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->goal_tolerance.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->goal_tolerance.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->goal_tolerance.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->goal_tolerance.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < goal_tolerance.size(); i++){
      offset += this->goal_tolerance[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->goal_time_tolerance.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->goal_time_tolerance.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->goal_time_tolerance.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->goal_time_tolerance.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_time_tolerance.sec);
      *(outbuffer + offset + 0) = (this->goal_time_tolerance.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->goal_time_tolerance.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->goal_time_tolerance.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->goal_time_tolerance.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_time_tolerance.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      uint32_t path_tolerance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      path_tolerance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      path_tolerance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      path_tolerance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      path_tolerance.resize(path_tolerance_lengthT);
      for( uint32_t i = 0; i < path_tolerance.size(); i++){
      offset += this->path_tolerance[i].deserialize(inbuffer + offset);
      }
      uint32_t goal_tolerance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      goal_tolerance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      goal_tolerance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      goal_tolerance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      goal_tolerance.resize(goal_tolerance_lengthT);
      for( uint32_t i = 0; i < goal_tolerance.size(); i++){
      offset += this->goal_tolerance[i].deserialize(inbuffer + offset);
      }
      this->goal_time_tolerance.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->goal_time_tolerance.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->goal_time_tolerance.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->goal_time_tolerance.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->goal_time_tolerance.sec);
      this->goal_time_tolerance.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->goal_time_tolerance.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->goal_time_tolerance.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->goal_time_tolerance.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->goal_time_tolerance.nsec);
     return offset;
    }

    const char * getType(){ return "control_msgs/FollowJointTrajectoryGoal"; };
    const char * getMD5(){ return "69636787b6ecbde4d61d711979bc7ecb"; };

  };

}
#endif