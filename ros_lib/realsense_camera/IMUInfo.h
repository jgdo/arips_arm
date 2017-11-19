#ifndef _ROS_realsense_camera_IMUInfo_h
#define _ROS_realsense_camera_IMUInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace realsense_camera
{

  class IMUInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::array<float, 12> data;
      std::array<float, 3> noise_variances;
      std::array<float, 3> bias_variances;

    IMUInfo():
      header(),
      data(),
      noise_variances(),
      bias_variances()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < data.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->data[i]);
      }
      for( uint32_t i = 0; i < noise_variances.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->noise_variances[i]);
      }
      for( uint32_t i = 0; i < bias_variances.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bias_variances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < data.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->data[i]));
      }
      for( uint32_t i = 0; i < noise_variances.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->noise_variances[i]));
      }
      for( uint32_t i = 0; i < bias_variances.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bias_variances[i]));
      }
     return offset;
    }

    const char * getType(){ return "realsense_camera/IMUInfo"; };
    const char * getMD5(){ return "b8a77fbb6e4146ae79c8a943413e4f62"; };

  };

}
#endif