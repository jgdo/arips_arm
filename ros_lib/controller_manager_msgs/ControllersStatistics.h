#ifndef _ROS_controller_manager_msgs_ControllersStatistics_h
#define _ROS_controller_manager_msgs_ControllersStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "controller_manager_msgs/ControllerStatistics.h"

namespace controller_manager_msgs
{

  class ControllersStatistics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<controller_manager_msgs::ControllerStatistics> controller;

    ControllersStatistics():
      header(),
      controller()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
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

    const char * getType(){ return "controller_manager_msgs/ControllersStatistics"; };
    const char * getMD5(){ return "a154c347736773e3700d1719105df29d"; };

  };

}
#endif