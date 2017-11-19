#ifndef _ROS_moveit_msgs_AllowedCollisionEntry_h
#define _ROS_moveit_msgs_AllowedCollisionEntry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace moveit_msgs
{

  class AllowedCollisionEntry : public ros::Msg
  {
    public:
      std::vector<bool> enabled;

    AllowedCollisionEntry():
      enabled()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->enabled.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->enabled.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->enabled.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->enabled.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < enabled.size(); i++){
      union {
        bool real;
        uint8_t base;
      } u_enabledi;
      u_enabledi.real = this->enabled[i];
      *(outbuffer + offset + 0) = (u_enabledi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t enabled_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      enabled_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      enabled.resize(enabled_lengthT);
      for( uint32_t i = 0; i < enabled.size(); i++){
      union {
        bool real;
        uint8_t base;
      } u_enabledi;
      u_enabledi.base = 0;
      u_enabledi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled[i] = u_enabledi.real;
      offset += sizeof(this->enabled[i]);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AllowedCollisionEntry"; };
    const char * getMD5(){ return "90d1ae1850840724bb043562fe3285fc"; };

  };

}
#endif