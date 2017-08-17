#ifndef _ROS_sensor_msgs_MultiDOFJointState_h
#define _ROS_sensor_msgs_MultiDOFJointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Wrench.h"

namespace sensor_msgs
{

  class MultiDOFJointState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<char*> joint_names;
      std::vector<geometry_msgs::Transform> transforms;
      std::vector<geometry_msgs::Twist> twist;
      std::vector<geometry_msgs::Wrench> wrench;

    MultiDOFJointState():
      header(),
      joint_names(),
      transforms(),
      twist(),
      wrench()
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
      *(outbuffer + offset + 0) = (this->transforms.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < transforms.size(); i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
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
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      transforms.resize(transforms_lengthT);
      for( uint32_t i = 0; i < transforms.size(); i++){
      offset += this->transforms[i].deserialize(inbuffer + offset);
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

    const char * getType(){ return "sensor_msgs/MultiDOFJointState"; };
    const char * getMD5(){ return "690f272f0640d2631c305eeb8301e59d"; };

  };

}
#endif