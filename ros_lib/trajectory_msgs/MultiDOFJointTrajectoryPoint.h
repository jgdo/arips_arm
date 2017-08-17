#ifndef _ROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h
#define _ROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/Twist.h"
#include "ros/duration.h"

namespace trajectory_msgs
{

  class MultiDOFJointTrajectoryPoint : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::Transform> transforms;
      std::vector<geometry_msgs::Twist> velocities;
      std::vector<geometry_msgs::Twist> accelerations;
      typedef ros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;

    MultiDOFJointTrajectoryPoint():
      transforms(),
      velocities(),
      accelerations(),
      time_from_start()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->transforms.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < transforms.size(); i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->velocities.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < velocities.size(); i++){
      offset += this->velocities[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->accelerations.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerations.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerations.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerations.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < accelerations.size(); i++){
      offset += this->accelerations[i].serialize(outbuffer + offset);
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
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      transforms.resize(transforms_lengthT);
      for( uint32_t i = 0; i < transforms.size(); i++){
      offset += this->transforms[i].deserialize(inbuffer + offset);
      }
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      velocities.resize(velocities_lengthT);
      for( uint32_t i = 0; i < velocities.size(); i++){
      offset += this->velocities[i].deserialize(inbuffer + offset);
      }
      uint32_t accelerations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      accelerations.resize(accelerations_lengthT);
      for( uint32_t i = 0; i < accelerations.size(); i++){
      offset += this->accelerations[i].deserialize(inbuffer + offset);
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

    const char * getType(){ return "trajectory_msgs/MultiDOFJointTrajectoryPoint"; };
    const char * getMD5(){ return "3ebe08d1abd5b65862d50e09430db776"; };

  };

}
#endif