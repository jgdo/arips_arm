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
      arips_arm_msgs::JointGoal goals[6];

    TrajectoryPoint():
      goals()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      offset += this->goals[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      offset += this->goals[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/TrajectoryPoint"; };
    const char * getMD5(){ return "3065f708f0d7f16303063e853e0c79c3"; };

  };

}
#endif