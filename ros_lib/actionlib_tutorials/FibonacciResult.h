#ifndef _ROS_actionlib_tutorials_FibonacciResult_h
#define _ROS_actionlib_tutorials_FibonacciResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace actionlib_tutorials
{

  class FibonacciResult : public ros::Msg
  {
    public:
      std::vector<int32_t> sequence;

    FibonacciResult():
      sequence()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sequence.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sequence.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sequence.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < sequence.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_sequencei;
      u_sequencei.real = this->sequence[i];
      *(outbuffer + offset + 0) = (u_sequencei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sequencei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sequencei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sequencei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t sequence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      sequence.resize(sequence_lengthT);
      for( uint32_t i = 0; i < sequence.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_sequencei;
      u_sequencei.base = 0;
      u_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sequencei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sequence[i] = u_sequencei.real;
      offset += sizeof(this->sequence[i]);
      }
     return offset;
    }

    const char * getType(){ return "actionlib_tutorials/FibonacciResult"; };
    const char * getMD5(){ return "b81e37d2a31925a0e8ae261a8699cb79"; };

  };

}
#endif