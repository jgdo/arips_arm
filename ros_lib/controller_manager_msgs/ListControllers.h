#ifndef _ROS_SERVICE_ListControllers_h
#define _ROS_SERVICE_ListControllers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "controller_manager_msgs/ControllerState.h"

namespace controller_manager_msgs
{

static const char LISTCONTROLLERS[] = "controller_manager_msgs/ListControllers";

  class ListControllersRequest : public ros::Msg
  {
    public:

    ListControllersRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LISTCONTROLLERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListControllersResponse : public ros::Msg
  {
    public:
      std::vector<controller_manager_msgs::ControllerState> controller;

    ListControllersResponse():
      controller()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->controller.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->controller.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->controller.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->controller.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < controller.size(); i++){
      offset += this->controller[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t controller_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      controller_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      controller_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      controller_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      controller.resize(controller_lengthT);
      for( uint32_t i = 0; i < controller.size(); i++){
      offset += this->controller[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return LISTCONTROLLERS; };
    const char * getMD5(){ return "1341feb2e63fa791f855565d0da950d8"; };

  };

  class ListControllers {
    public:
    typedef ListControllersRequest Request;
    typedef ListControllersResponse Response;
  };

}
#endif
