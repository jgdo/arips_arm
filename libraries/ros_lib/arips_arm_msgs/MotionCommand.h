#ifndef _ROS_arips_arm_msgs_MotionCommand_h
#define _ROS_arips_arm_msgs_MotionCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class MotionCommand : public ros::Msg
  {
    public:
      typedef uint8_t _command_type;
      _command_type command;
      typedef float _st_position_type;
      _st_position_type st_position;
      enum { CMD_RELEASE =  5	 };
      enum { CMD_BREAK =  10	 };
      enum { CMD_HOLD =  15		 };
      enum { CMD_RAW_MOTORS =  20		 };
      enum { CMD_DIRECT_JOINTS =  21    };
      enum { CMD_DIRECT_CONTROLLER =  22   };
      enum { CMD_START_TRAJECTORY =  30	 };

    MotionCommand():
      command(0),
      st_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      union {
        float real;
        uint32_t base;
      } u_st_position;
      u_st_position.real = this->st_position;
      *(outbuffer + offset + 0) = (u_st_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_st_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_st_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_st_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->st_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      union {
        float real;
        uint32_t base;
      } u_st_position;
      u_st_position.base = 0;
      u_st_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_position = u_st_position.real;
      offset += sizeof(this->st_position);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/MotionCommand"; };
    const char * getMD5(){ return "349ff2d00106b157db750ee85773799c"; };

  };

}
#endif