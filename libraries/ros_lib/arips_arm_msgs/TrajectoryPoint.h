#ifndef _ROS_arips_arm_msgs_TrajectoryPoint_h
#define _ROS_arips_arm_msgs_TrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/JointGoal.h"

namespace arips_arm_msgs
{

  class TrajectoryPoint : public ros::Msg
  {
    public:
      arips_arm_msgs::JointGoal goals[5];
      typedef uint32_t _timeFromStart_ms_type;
      _timeFromStart_ms_type timeFromStart_ms;

    TrajectoryPoint():
      goals(),
      timeFromStart_ms(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      offset += this->goals[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->timeFromStart_ms >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeFromStart_ms >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeFromStart_ms >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeFromStart_ms >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeFromStart_ms);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 5; i++){
      offset += this->goals[i].deserialize(inbuffer + offset);
      }
      this->timeFromStart_ms =  ((uint32_t) (*(inbuffer + offset)));
      this->timeFromStart_ms |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeFromStart_ms |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeFromStart_ms |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeFromStart_ms);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/TrajectoryPoint"; };
    const char * getMD5(){ return "c8de78bdccf2c46c0807b468965e4af8"; };

  };

}
#endif