#ifndef _ROS_arips_msgs_ServoPosition_h
#define _ROS_arips_msgs_ServoPosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_msgs
{

  class ServoPosition : public ros::Msg
  {
    public:
      typedef uint32_t _mask_type;
      _mask_type mask;
      uint32_t positions_length;
      typedef float _positions_type;
      _positions_type st_positions;
      _positions_type * positions;

    ServoPosition():
      mask(0),
      positions_length(0), positions(NULL)
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
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
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
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_positions;
      u_st_positions.base = 0;
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_positions = u_st_positions.real;
      offset += sizeof(this->st_positions);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/ServoPosition"; };
    const char * getMD5(){ return "1259631a2889d030eef29382ca1d6de3"; };

  };

}
#endif