#ifndef _ROS_arips_msgs_MotorPWMRawArray_h
#define _ROS_arips_msgs_MotorPWMRawArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "arips_msgs/MotorPWMRaw.h"

namespace arips_msgs
{

  class MotorPWMRawArray : public ros::Msg
  {
    public:
      std::vector<arips_msgs::MotorPWMRaw> motor_pwm;

    MotorPWMRawArray():
      motor_pwm()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_pwm.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_pwm.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_pwm.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_pwm.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < motor_pwm.size(); i++){
      offset += this->motor_pwm[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t motor_pwm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_pwm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_pwm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_pwm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      motor_pwm.resize(motor_pwm_lengthT);
      for( uint32_t i = 0; i < motor_pwm.size(); i++){
      offset += this->motor_pwm[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/MotorPWMRawArray"; };
    const char * getMD5(){ return "2c0cb1c741eca47347b739f5f254a77c"; };

  };

}
#endif