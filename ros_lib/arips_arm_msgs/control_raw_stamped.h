#ifndef _ROS_arips_arm_msgs_control_raw_stamped_h
#define _ROS_arips_arm_msgs_control_raw_stamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "ros/time.h"

namespace arips_arm_msgs
{

  class control_raw_stamped : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      std::array<uint16_t, 2> adc_raw;
      std::array<float, 2> adc;
      std::array<float, 2> out;
      std::array<uint16_t, 2> out_raw;

    control_raw_stamped():
      stamp(),
      adc_raw(),
      adc(),
      out(),
      out_raw()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      for( uint32_t i = 0; i < adc_raw.size(); i++){
      *(outbuffer + offset + 0) = (this->adc_raw[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->adc_raw[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->adc_raw[i]);
      }
      for( uint32_t i = 0; i < adc.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_adci;
      u_adci.real = this->adc[i];
      *(outbuffer + offset + 0) = (u_adci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_adci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_adci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_adci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->adc[i]);
      }
      for( uint32_t i = 0; i < out.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_outi;
      u_outi.real = this->out[i];
      *(outbuffer + offset + 0) = (u_outi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_outi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_outi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_outi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->out[i]);
      }
      for( uint32_t i = 0; i < out_raw.size(); i++){
      *(outbuffer + offset + 0) = (this->out_raw[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->out_raw[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->out_raw[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      for( uint32_t i = 0; i < adc_raw.size(); i++){
      this->adc_raw[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->adc_raw[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->adc_raw[i]);
      }
      for( uint32_t i = 0; i < adc.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_adci;
      u_adci.base = 0;
      u_adci.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_adci.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_adci.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_adci.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->adc[i] = u_adci.real;
      offset += sizeof(this->adc[i]);
      }
      for( uint32_t i = 0; i < out.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_outi;
      u_outi.base = 0;
      u_outi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_outi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_outi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_outi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->out[i] = u_outi.real;
      offset += sizeof(this->out[i]);
      }
      for( uint32_t i = 0; i < out_raw.size(); i++){
      this->out_raw[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->out_raw[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->out_raw[i]);
      }
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/control_raw_stamped"; };
    const char * getMD5(){ return "dbee0c2cba946c315ca1a901366fd7e5"; };

  };

}
#endif