#ifndef _ROS_gazebo_msgs_ContactsState_h
#define _ROS_gazebo_msgs_ContactsState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "gazebo_msgs/ContactState.h"

namespace gazebo_msgs
{

  class ContactsState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<gazebo_msgs::ContactState> states;

    ContactsState():
      header(),
      states()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->states.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < states.size(); i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      states.resize(states_lengthT);
      for( uint32_t i = 0; i < states.size(); i++){
      offset += this->states[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ContactsState"; };
    const char * getMD5(){ return "acbcb1601a8e525bf72509f18e6f668d"; };

  };

}
#endif