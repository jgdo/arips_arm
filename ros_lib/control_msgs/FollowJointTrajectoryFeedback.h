#ifndef _ROS_control_msgs_FollowJointTrajectoryFeedback_h
#define _ROS_control_msgs_FollowJointTrajectoryFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"

namespace control_msgs
{

  class FollowJointTrajectoryFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<char*> joint_names;
      typedef trajectory_msgs::JointTrajectoryPoint _desired_type;
      _desired_type desired;
      typedef trajectory_msgs::JointTrajectoryPoint _actual_type;
      _actual_type actual;
      typedef trajectory_msgs::JointTrajectoryPoint _error_type;
      _error_type error;

    FollowJointTrajectoryFeedback():
      header(),
      joint_names(),
      desired(),
      actual(),
      error()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->joint_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < joint_names.size(); i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      offset += this->desired.serialize(outbuffer + offset);
      offset += this->actual.serialize(outbuffer + offset);
      offset += this->error.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      joint_names.resize(joint_names_lengthT);
      for( uint32_t i = 0; i < joint_names.size(); i++){
      uint32_t length_joint_namesi;
      arrToVar(length_joint_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_namesi-1]=0;
      this->joint_names[i] = (char *)(inbuffer + offset-1);
      offset += length_joint_namesi;
      }
      offset += this->desired.deserialize(inbuffer + offset);
      offset += this->actual.deserialize(inbuffer + offset);
      offset += this->error.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "control_msgs/FollowJointTrajectoryFeedback"; };
    const char * getMD5(){ return "10817c60c2486ef6b33e97dcd87f4474"; };

  };

}
#endif