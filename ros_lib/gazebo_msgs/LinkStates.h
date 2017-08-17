#ifndef _ROS_gazebo_msgs_LinkStates_h
#define _ROS_gazebo_msgs_LinkStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"

namespace gazebo_msgs
{

  class LinkStates : public ros::Msg
  {
    public:
      std::vector<char*> name;
      std::vector<geometry_msgs::Pose> pose;
      std::vector<geometry_msgs::Twist> twist;

    LinkStates():
      name(),
      pose(),
      twist()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/LinkStates"; };
    const char * getMD5(){ return "48c080191eb15c41858319b4d8a609c2"; };

  };

}
#endif