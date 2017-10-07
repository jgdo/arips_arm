#ifndef _ROS_moveit_msgs_Constraints_h
#define _ROS_moveit_msgs_Constraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/JointConstraint.h"
#include "moveit_msgs/PositionConstraint.h"
#include "moveit_msgs/OrientationConstraint.h"
#include "moveit_msgs/VisibilityConstraint.h"

namespace moveit_msgs
{

  class Constraints : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      std::vector<moveit_msgs::JointConstraint> joint_constraints;
      std::vector<moveit_msgs::PositionConstraint> position_constraints;
      std::vector<moveit_msgs::OrientationConstraint> orientation_constraints;
      std::vector<moveit_msgs::VisibilityConstraint> visibility_constraints;

    Constraints():
      name(""),
      joint_constraints(),
      position_constraints(),
      orientation_constraints(),
      visibility_constraints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->joint_constraints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_constraints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_constraints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_constraints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < joint_constraints.size(); i++){
      offset += this->joint_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->position_constraints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_constraints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_constraints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_constraints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < position_constraints.size(); i++){
      offset += this->position_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->orientation_constraints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientation_constraints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->orientation_constraints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->orientation_constraints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < orientation_constraints.size(); i++){
      offset += this->orientation_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->visibility_constraints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->visibility_constraints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->visibility_constraints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->visibility_constraints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < visibility_constraints.size(); i++){
      offset += this->visibility_constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t joint_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      joint_constraints.resize(joint_constraints_lengthT);
      for( uint32_t i = 0; i < joint_constraints.size(); i++){
      offset += this->joint_constraints[i].deserialize(inbuffer + offset);
      }
      uint32_t position_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      position_constraints.resize(position_constraints_lengthT);
      for( uint32_t i = 0; i < position_constraints.size(); i++){
      offset += this->position_constraints[i].deserialize(inbuffer + offset);
      }
      uint32_t orientation_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      orientation_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      orientation_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      orientation_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      orientation_constraints.resize(orientation_constraints_lengthT);
      for( uint32_t i = 0; i < orientation_constraints.size(); i++){
      offset += this->orientation_constraints[i].deserialize(inbuffer + offset);
      }
      uint32_t visibility_constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      visibility_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      visibility_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      visibility_constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      visibility_constraints.resize(visibility_constraints_lengthT);
      for( uint32_t i = 0; i < visibility_constraints.size(); i++){
      offset += this->visibility_constraints[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/Constraints"; };
    const char * getMD5(){ return "8d5ce8d34ef26c65fb5d43c9e99bf6e0"; };

  };

}
#endif