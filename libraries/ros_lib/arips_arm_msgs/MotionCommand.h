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
      enum { CMD_RELEASE =  5	 };
      enum { CMD_BREAK =  10	 };
      enum { CMD_HOLD =  15		 };
      enum { CMD_RAW_MOTORS =  20		 };
      enum { CMD_DIRECT_JOINTS =  21    };
      enum { CMD_DIRECT_CONTROLLER =  22   };
      enum { CMD_START_TRAJECTORY =  30	 };

    MotionCommand():
      command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/MotionCommand"; };
    const char * getMD5(){ return "d6f4b0a03e2f977f0a6a8d4a298bb2d5"; };

  };

}
#endif