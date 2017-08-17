#ifndef _ROS_trajectory_msgs_JointTrajectoryPoint_h
#define _ROS_trajectory_msgs_JointTrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "ros/duration.h"

namespace trajectory_msgs
{

  class JointTrajectoryPoint : public ros::Msg
  {
    public:
      std::vector<float> positions;
      std::vector<float> velocities;
      std::vector<float> accelerations;
      std::vector<float> effort;
      typedef ros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;

    JointTrajectoryPoint():
      positions(),
      velocities(),
      accelerations(),
      effort(),
      time_from_start()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->positions.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < positions.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->positions[i]);
      }
      *(outbuffer + offset + 0) = (this->velocities.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < velocities.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocities[i]);
      }
      *(outbuffer + offset + 0) = (this->accelerations.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerations.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerations.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerations.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < accelerations.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->accelerations[i]);
      }
      *(outbuffer + offset + 0) = (this->effort.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < effort.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->effort[i]);
      }
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      positions.resize(positions_lengthT);
      for( uint32_t i = 0; i < positions.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->positions[i]));
      }
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      velocities.resize(velocities_lengthT);
      for( uint32_t i = 0; i < velocities.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocities[i]));
      }
      uint32_t accelerations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      accelerations.resize(accelerations_lengthT);
      for( uint32_t i = 0; i < accelerations.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accelerations[i]));
      }
      uint32_t effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      effort.resize(effort_lengthT);
      for( uint32_t i = 0; i < effort.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->effort[i]));
      }
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
     return offset;
    }

    const char * getType(){ return "trajectory_msgs/JointTrajectoryPoint"; };
    const char * getMD5(){ return "f3cd1e1c4d320c79d6985c904ae5dcd3"; };

  };

}
#endif