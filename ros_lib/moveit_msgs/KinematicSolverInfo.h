#ifndef _ROS_moveit_msgs_KinematicSolverInfo_h
#define _ROS_moveit_msgs_KinematicSolverInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/JointLimits.h"

namespace moveit_msgs
{

  class KinematicSolverInfo : public ros::Msg
  {
    public:
      std::vector<char*> joint_names;
      std::vector<moveit_msgs::JointLimits> limits;
      std::vector<char*> link_names;

    KinematicSolverInfo():
      joint_names(),
      limits(),
      link_names()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      *(outbuffer + offset + 0) = (this->limits.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limits.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->limits.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->limits.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < limits.size(); i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->link_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < link_names.size(); i++){
      uint32_t length_link_namesi = strlen(this->link_names[i]);
      varToArr(outbuffer + offset, length_link_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->link_names[i], length_link_namesi);
      offset += length_link_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint32_t limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      limits.resize(limits_lengthT);
      for( uint32_t i = 0; i < limits.size(); i++){
      offset += this->limits[i].deserialize(inbuffer + offset);
      }
      uint32_t link_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      link_names.resize(link_names_lengthT);
      for( uint32_t i = 0; i < link_names.size(); i++){
      uint32_t length_link_namesi;
      arrToVar(length_link_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_namesi-1]=0;
      this->link_names[i] = (char *)(inbuffer + offset-1);
      offset += length_link_namesi;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/KinematicSolverInfo"; };
    const char * getMD5(){ return "cc048557c0f9795c392dd80f8bb00489"; };

  };

}
#endif