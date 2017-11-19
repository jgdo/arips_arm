#ifndef _ROS_moveit_msgs_DisplayRobotState_h
#define _ROS_moveit_msgs_DisplayRobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/ObjectColor.h"

namespace moveit_msgs
{

  class DisplayRobotState : public ros::Msg
  {
    public:
      typedef moveit_msgs::RobotState _state_type;
      _state_type state;
      std::vector<moveit_msgs::ObjectColor> highlight_links;

    DisplayRobotState():
      state(),
      highlight_links()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->highlight_links.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->highlight_links.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->highlight_links.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->highlight_links.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < highlight_links.size(); i++){
      offset += this->highlight_links[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
      uint32_t highlight_links_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      highlight_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      highlight_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      highlight_links_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      highlight_links.resize(highlight_links_lengthT);
      for( uint32_t i = 0; i < highlight_links.size(); i++){
      offset += this->highlight_links[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/DisplayRobotState"; };
    const char * getMD5(){ return "6a3bab3a33a8c47aee24481a455a21aa"; };

  };

}
#endif