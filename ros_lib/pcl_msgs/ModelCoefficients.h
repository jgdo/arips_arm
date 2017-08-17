#ifndef _ROS_pcl_msgs_ModelCoefficients_h
#define _ROS_pcl_msgs_ModelCoefficients_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pcl_msgs
{

  class ModelCoefficients : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<float> values;

    ModelCoefficients():
      header(),
      values()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->values.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->values.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->values.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->values.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < values.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_valuesi;
      u_valuesi.real = this->values[i];
      *(outbuffer + offset + 0) = (u_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      values.resize(values_lengthT);
      for( uint32_t i = 0; i < values.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_valuesi;
      u_valuesi.base = 0;
      u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->values[i] = u_valuesi.real;
      offset += sizeof(this->values[i]);
      }
     return offset;
    }

    const char * getType(){ return "pcl_msgs/ModelCoefficients"; };
    const char * getMD5(){ return "ca27dea75e72cb894cd36f9e5005e93e"; };

  };

}
#endif