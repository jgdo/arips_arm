#ifndef _ROS_arips_arm_msgs_JointState_h
#define _ROS_arips_arm_msgs_JointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class JointState : public ros::Msg
  {
    public:
      typedef uint16_t _adc_raw_type;
      _adc_raw_type adc_raw;
      typedef float _position_type;
      _position_type position;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _setpoint_pos_type;
      _setpoint_pos_type setpoint_pos;
      typedef float _setpoint_vel_type;
      _setpoint_vel_type setpoint_vel;
      typedef float _pwm_type;
      _pwm_type pwm;

    JointState():
      adc_raw(0),
      position(0),
      velocity(0),
      setpoint_pos(0),
      setpoint_vel(0),
      pwm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->adc_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->adc_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->adc_raw);
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_setpoint_pos;
      u_setpoint_pos.real = this->setpoint_pos;
      *(outbuffer + offset + 0) = (u_setpoint_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setpoint_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setpoint_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setpoint_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpoint_pos);
      union {
        float real;
        uint32_t base;
      } u_setpoint_vel;
      u_setpoint_vel.real = this->setpoint_vel;
      *(outbuffer + offset + 0) = (u_setpoint_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setpoint_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setpoint_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setpoint_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpoint_vel);
      union {
        float real;
        uint32_t base;
      } u_pwm;
      u_pwm.real = this->pwm;
      *(outbuffer + offset + 0) = (u_pwm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pwm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pwm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pwm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pwm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->adc_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->adc_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->adc_raw);
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position = u_position.real;
      offset += sizeof(this->position);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_setpoint_pos;
      u_setpoint_pos.base = 0;
      u_setpoint_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_setpoint_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_setpoint_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_setpoint_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->setpoint_pos = u_setpoint_pos.real;
      offset += sizeof(this->setpoint_pos);
      union {
        float real;
        uint32_t base;
      } u_setpoint_vel;
      u_setpoint_vel.base = 0;
      u_setpoint_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_setpoint_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_setpoint_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_setpoint_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->setpoint_vel = u_setpoint_vel.real;
      offset += sizeof(this->setpoint_vel);
      union {
        float real;
        uint32_t base;
      } u_pwm;
      u_pwm.base = 0;
      u_pwm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pwm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pwm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pwm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pwm = u_pwm.real;
      offset += sizeof(this->pwm);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/JointState"; };
    const char * getMD5(){ return "ae83d1b119231978165cc2d165630f2b"; };

  };

}
#endif