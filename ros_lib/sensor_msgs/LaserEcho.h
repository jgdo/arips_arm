#ifndef _ROS_sensor_msgs_LaserEcho_h
#define _ROS_sensor_msgs_LaserEcho_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace sensor_msgs
{

  class LaserEcho : public ros::Msg
  {
    public:
      std::vector<float> echoes;

    LaserEcho():
      echoes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->echoes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->echoes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->echoes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->echoes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < echoes.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_echoesi;
      u_echoesi.real = this->echoes[i];
      *(outbuffer + offset + 0) = (u_echoesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_echoesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_echoesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_echoesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->echoes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t echoes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      echoes.resize(echoes_lengthT);
      for( uint32_t i = 0; i < echoes.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_echoesi;
      u_echoesi.base = 0;
      u_echoesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_echoesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_echoesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_echoesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->echoes[i] = u_echoesi.real;
      offset += sizeof(this->echoes[i]);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/LaserEcho"; };
    const char * getMD5(){ return "8bc5ae449b200fba4d552b4225586696"; };

  };

}
#endif