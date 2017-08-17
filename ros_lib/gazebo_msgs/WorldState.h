#ifndef _ROS_gazebo_msgs_WorldState_h
#define _ROS_gazebo_msgs_WorldState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Wrench.h"

namespace gazebo_msgs
{

  class WorldState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<char*> name;
      std::vector<geometry_msgs::Pose> pose;
      std::vector<geometry_msgs::Twist> twist;
      std::vector<geometry_msgs::Wrench> wrench;

    WorldState():
      header(),
      name(),
      pose(),
      twist(),
      wrench()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->name.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < name.size(); i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->pose.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < pose.size(); i++){
      offset += this->pose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->twist.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->twist.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->twist.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->twist.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < twist.size(); i++){
      offset += this->twist[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->wrench.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wrench.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wrench.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wrench.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < wrench.size(); i++){
      offset += this->wrench[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      name.resize(name_lengthT);
      for( uint32_t i = 0; i < name.size(); i++){
      uint32_t length_namei;
      arrToVar(length_namei, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namei; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namei-1]=0;
      this->name[i] = (char *)(inbuffer + offset-1);
      offset += length_namei;
      }
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      pose.resize(pose_lengthT);
      for( uint32_t i = 0; i < pose.size(); i++){
      offset += this->pose[i].deserialize(inbuffer + offset);
      }
      uint32_t twist_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      twist.resize(twist_lengthT);
      for( uint32_t i = 0; i < twist.size(); i++){
      offset += this->twist[i].deserialize(inbuffer + offset);
      }
      uint32_t wrench_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      wrench.resize(wrench_lengthT);
      for( uint32_t i = 0; i < wrench.size(); i++){
      offset += this->wrench[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/WorldState"; };
    const char * getMD5(){ return "de1a9de3ab7ba97ac0e9ec01a4eb481e"; };

  };

}
#endif