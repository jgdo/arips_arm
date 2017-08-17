#ifndef _ROS_arips_msgs_SensorState_h
#define _ROS_arips_msgs_SensorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace arips_msgs
{

  class SensorState : public ros::Msg
  {
    public:
      std::vector<int16_t> ADC;

    SensorState():
      ADC()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ADC.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ADC.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ADC.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ADC.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < ADC.size(); i++){
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
      offset += 4;
      ADC.resize(ADC_lengthT);
      for( uint32_t i = 0; i < ADC.size(); i++){
      union {
        int16_t real;
        uint16_t base;
      } u_ADCi;
      u_ADCi.base = 0;
      u_ADCi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ADCi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ADC[i] = u_ADCi.real;
      offset += sizeof(this->ADC[i]);
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/SensorState"; };
    const char * getMD5(){ return "85629c8256dbbce843797ff45463c656"; };

  };

}
#endif