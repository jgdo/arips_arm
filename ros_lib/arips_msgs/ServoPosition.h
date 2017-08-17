#ifndef _ROS_arips_msgs_ServoPosition_h
#define _ROS_arips_msgs_ServoPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace arips_msgs
{

  class ServoPosition : public ros::Msg
  {
    public:
      typedef uint32_t _mask_type;
      _mask_type mask;
      std::vector<float> positions;

    ServoPosition():
      mask(0),
      positions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mask >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mask >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mask >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mask);
      *(outbuffer + offset + 0) = (this->positions.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < positions.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_positionsi;
      u_positionsi.real = this->positions[i];
      *(outbuffer + offset + 0) = (u_positionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positionsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mask =  ((uint32_t) (*(inbuffer + offset)));
      this->mask |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mask |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mask |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mask);
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      positions.resize(positions_lengthT);
      for( uint32_t i = 0; i < positions.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_positionsi;
      u_positionsi.base = 0;
      u_positionsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_positionsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_positionsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_positionsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->positions[i] = u_positionsi.real;
      offset += sizeof(this->positions[i]);
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/ServoPosition"; };
    const char * getMD5(){ return "1259631a2889d030eef29382ca1d6de3"; };

  };

}
#endif