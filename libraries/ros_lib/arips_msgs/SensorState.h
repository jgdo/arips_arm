#ifndef _ROS_arips_msgs_SensorState_h
#define _ROS_arips_msgs_SensorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_msgs
{

  class SensorState : public ros::Msg
  {
    public:
      uint32_t ADC_length;
      typedef int16_t _ADC_type;
      _ADC_type st_ADC;
      _ADC_type * ADC;

    SensorState():
      ADC_length(0), ADC(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ADC_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ADC_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ADC_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ADC_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ADC_length);
      for( uint32_t i = 0; i < ADC_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_ADCi;
      u_ADCi.real = this->ADC[i];
      *(outbuffer + offset + 0) = (u_ADCi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ADCi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ADC[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t ADC_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ADC_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ADC_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ADC_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ADC_length);
      if(ADC_lengthT > ADC_length)
        this->ADC = (int16_t*)realloc(this->ADC, ADC_lengthT * sizeof(int16_t));
      ADC_length = ADC_lengthT;
      for( uint32_t i = 0; i < ADC_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_ADC;
      u_st_ADC.base = 0;
      u_st_ADC.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ADC.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_ADC = u_st_ADC.real;
      offset += sizeof(this->st_ADC);
        memcpy( &(this->ADC[i]), &(this->st_ADC), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/SensorState"; };
    const char * getMD5(){ return "85629c8256dbbce843797ff45463c656"; };

  };

}
#endif