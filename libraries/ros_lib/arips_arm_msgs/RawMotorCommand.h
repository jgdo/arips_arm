#ifndef _ROS_arips_arm_msgs_RawMotorCommand_h
#define _ROS_arips_arm_msgs_RawMotorCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class RawMotorCommand : public ros::Msg
  {
    public:
      float raw_motor_power[5];

    RawMotorCommand():
      raw_motor_power()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_raw_motor_poweri;
      u_raw_motor_poweri.real = this->raw_motor_power[i];
      *(outbuffer + offset + 0) = (u_raw_motor_poweri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_motor_poweri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_motor_poweri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_motor_poweri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_motor_power[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_raw_motor_poweri;
      u_raw_motor_poweri.base = 0;
      u_raw_motor_poweri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_motor_poweri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_motor_poweri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_motor_poweri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->raw_motor_power[i] = u_raw_motor_poweri.real;
      offset += sizeof(this->raw_motor_power[i]);
      }
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/RawMotorCommand"; };
    const char * getMD5(){ return "b54b3eaf4bcd0b062aa354b1a0135ad0"; };

  };

}
#endif