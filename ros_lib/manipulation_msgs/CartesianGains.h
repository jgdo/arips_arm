#ifndef _ROS_manipulation_msgs_CartesianGains_h
#define _ROS_manipulation_msgs_CartesianGains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace manipulation_msgs
{

  class CartesianGains : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<float> gains;
      std::vector<float> fixed_frame;

    CartesianGains():
      header(),
      gains(),
      fixed_frame()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->gains.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gains.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gains.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gains.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < gains.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gains[i]);
      }
      *(outbuffer + offset + 0) = (this->fixed_frame.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fixed_frame.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fixed_frame.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fixed_frame.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fixed_frame.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->fixed_frame[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t gains_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gains_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gains_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gains_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      gains.resize(gains_lengthT);
      for( uint32_t i = 0; i < gains.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gains[i]));
      }
      uint32_t fixed_frame_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fixed_frame_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fixed_frame_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fixed_frame_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fixed_frame.resize(fixed_frame_lengthT);
      for( uint32_t i = 0; i < fixed_frame.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fixed_frame[i]));
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/CartesianGains"; };
    const char * getMD5(){ return "ab347f046ca5736a156ec424cbb63635"; };

  };

}
#endif