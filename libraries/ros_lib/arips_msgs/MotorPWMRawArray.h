#ifndef _ROS_arips_msgs_MotorPWMRawArray_h
#define _ROS_arips_msgs_MotorPWMRawArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_msgs/MotorPWMRaw.h"

namespace arips_msgs
{

  class MotorPWMRawArray : public ros::Msg
  {
    public:
      uint32_t motor_pwm_length;
      typedef arips_msgs::MotorPWMRaw _motor_pwm_type;
      _motor_pwm_type st_motor_pwm;
      _motor_pwm_type * motor_pwm;

    MotorPWMRawArray():
      motor_pwm_length(0), motor_pwm(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor_pwm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_pwm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_pwm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_pwm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_pwm_length);
      for( uint32_t i = 0; i < motor_pwm_length; i++){
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
      offset += sizeof(this->motor_pwm_length);
      if(motor_pwm_lengthT > motor_pwm_length)
        this->motor_pwm = (arips_msgs::MotorPWMRaw*)realloc(this->motor_pwm, motor_pwm_lengthT * sizeof(arips_msgs::MotorPWMRaw));
      motor_pwm_length = motor_pwm_lengthT;
      for( uint32_t i = 0; i < motor_pwm_length; i++){
      offset += this->st_motor_pwm.deserialize(inbuffer + offset);
        memcpy( &(this->motor_pwm[i]), &(this->st_motor_pwm), sizeof(arips_msgs::MotorPWMRaw));
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/MotorPWMRawArray"; };
    const char * getMD5(){ return "2c0cb1c741eca47347b739f5f254a77c"; };

  };

}
#endif