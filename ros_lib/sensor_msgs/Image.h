#ifndef _ROS_sensor_msgs_Image_h
#define _ROS_sensor_msgs_Image_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class Image : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _height_type;
      _height_type height;
      typedef uint32_t _width_type;
      _width_type width;
      typedef const char* _encoding_type;
      _encoding_type encoding;
      typedef uint8_t _is_bigendian_type;
      _is_bigendian_type is_bigendian;
      typedef uint32_t _step_type;
      _step_type step;
      std::vector<uint8_t> data;

    Image():
      header(),
      height(0),
      width(0),
      encoding(""),
      is_bigendian(0),
      step(0),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      uint32_t length_encoding = strlen(this->encoding);
      varToArr(outbuffer + offset, length_encoding);
      offset += 4;
      memcpy(outbuffer + offset, this->encoding, length_encoding);
      offset += length_encoding;
      *(outbuffer + offset + 0) = (this->is_bigendian >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_bigendian);
      *(outbuffer + offset + 0) = (this->step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step);
      *(outbuffer + offset + 0) = (this->data.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < data.size(); i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      uint32_t length_encoding;
      arrToVar(length_encoding, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_encoding; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_encoding-1]=0;
      this->encoding = (char *)(inbuffer + offset-1);
      offset += length_encoding;
      this->is_bigendian =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->is_bigendian);
      this->step =  ((uint32_t) (*(inbuffer + offset)));
      this->step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->step);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      data.resize(data_lengthT);
      for( uint32_t i = 0; i < data.size(); i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Image"; };
    const char * getMD5(){ return "060021388200f6f0f447d0fcd9c64743"; };

  };

}
#endif