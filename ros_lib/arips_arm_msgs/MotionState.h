#ifndef _ROS_arips_arm_msgs_MotionState_h
#define _ROS_arips_arm_msgs_MotionState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "ros/time.h"
#include "arips_arm_msgs/JointState.h"
#include "arips_arm_msgs/TrajectoryState.h"

namespace arips_arm_msgs
{

  class MotionState : public ros::Msg
  {
    public:
      typedef uint32_t _mode_type;
      _mode_type mode;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      std::array<arips_arm_msgs::JointState, 1> jointStates;
      typedef arips_arm_msgs::TrajectoryState _trajState_type;
      _trajState_type trajState;
      enum { M_IDLE =  0  };
      enum { M_BREAK =  1  };
      enum { M_HOLD =  2  };
      enum { M_SINGLE_GOAL =  3  };
      enum { M_TRAJECTORY =  4  };

    MotionState():
      mode(0),
      stamp(),
      jointStates(),
      trajState()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mode >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mode >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
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
      for( uint32_t i = 0; i < jointStates.size(); i++){
      offset += this->jointStates[i].serialize(outbuffer + offset);
      }
      offset += this->trajState.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mode =  ((uint32_t) (*(inbuffer + offset)));
      this->mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mode);
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
      for( uint32_t i = 0; i < jointStates.size(); i++){
      offset += this->jointStates[i].deserialize(inbuffer + offset);
      }
      offset += this->trajState.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/MotionState"; };
    const char * getMD5(){ return "1f40d7d0b4c0764825a5c971787cbacd"; };

  };

}
#endif