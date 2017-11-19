#ifndef _ROS_arips_arm_msgs_control_state_h
#define _ROS_arips_arm_msgs_control_state_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class control_state : public ros::Msg
  {
    public:
      typedef uint16_t _input_raw_type;
      _input_raw_type input_raw;
      typedef float _input_pos_type;
      _input_pos_type input_pos;
      typedef float _input_vel_type;
      _input_vel_type input_vel;
      typedef float _output_type;
      _output_type output;
      typedef uint16_t _output_raw_type;
      _output_raw_type output_raw;
      typedef float _setpoint_pos_type;
      _setpoint_pos_type setpoint_pos;
      typedef float _setpoint_vel_type;
      _setpoint_vel_type setpoint_vel;

    control_state():
      input_raw(0),
      input_pos(0),
      input_vel(0),
      output(0),
      output_raw(0),
      setpoint_pos(0),
      setpoint_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->input_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->input_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->input_raw);
      union {
        float real;
        uint32_t base;
      } u_input_pos;
      u_input_pos.real = this->input_pos;
      *(outbuffer + offset + 0) = (u_input_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_pos);
      union {
        float real;
        uint32_t base;
      } u_input_vel;
      u_input_vel.real = this->input_vel;
      *(outbuffer + offset + 0) = (u_input_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_vel);
      union {
        float real;
        uint32_t base;
      } u_output;
      u_output.real = this->output;
      *(outbuffer + offset + 0) = (u_output.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_output.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_output.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_output.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->output);
      *(outbuffer + offset + 0) = (this->output_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->output_raw >> (8 * 1)) & 0xFF;
      offset += sizeof(this->output_raw);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->input_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->input_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->input_raw);
      union {
        float real;
        uint32_t base;
      } u_input_pos;
      u_input_pos.base = 0;
      u_input_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_pos = u_input_pos.real;
      offset += sizeof(this->input_pos);
      union {
        float real;
        uint32_t base;
      } u_input_vel;
      u_input_vel.base = 0;
      u_input_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_vel = u_input_vel.real;
      offset += sizeof(this->input_vel);
      union {
        float real;
        uint32_t base;
      } u_output;
      u_output.base = 0;
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_output.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->output = u_output.real;
      offset += sizeof(this->output);
      this->output_raw =  ((uint16_t) (*(inbuffer + offset)));
      this->output_raw |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->output_raw);
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
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/control_state"; };
    const char * getMD5(){ return "d9338dd118c28ae03a4b934027e5c4a0"; };

  };

}
#endif