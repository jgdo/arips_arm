#ifndef _ROS_moveit_msgs_TrajectoryConstraints_h
#define _ROS_moveit_msgs_TrajectoryConstraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/Constraints.h"

namespace moveit_msgs
{

  class TrajectoryConstraints : public ros::Msg
  {
    public:
      std::vector<moveit_msgs::Constraints> constraints;

    TrajectoryConstraints():
      constraints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->constraints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->constraints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->constraints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->constraints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < constraints.size(); i++){
      offset += this->constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t constraints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      constraints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      constraints.resize(constraints_lengthT);
      for( uint32_t i = 0; i < constraints.size(); i++){
      offset += this->constraints[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/TrajectoryConstraints"; };
    const char * getMD5(){ return "461e1a732dfebb01e7d6c75d51a51eac"; };

  };

}
#endif