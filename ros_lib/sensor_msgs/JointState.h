#ifndef _ROS_sensor_msgs_JointState_h
#define _ROS_sensor_msgs_JointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class JointState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<char*> name;
      std::vector<float> position;
      std::vector<float> velocity;
      std::vector<float> effort;

    JointState():
      header(),
      name(),
      position(),
      velocity(),
      effort()
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
      *(outbuffer + offset + 0) = (this->position.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < position.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->position[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < velocity.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->effort.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < effort.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->effort[i]);
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
      uint32_t position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      position.resize(position_lengthT);
      for( uint32_t i = 0; i < position.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position[i]));
      }
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      velocity.resize(velocity_lengthT);
      for( uint32_t i = 0; i < velocity.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity[i]));
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
     return offset;
    }

    const char * getType(){ return "sensor_msgs/JointState"; };
    const char * getMD5(){ return "3066dcd76a6cfaef579bd0f34173e9fd"; };

  };

}
#endif