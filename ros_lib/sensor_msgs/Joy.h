#ifndef _ROS_sensor_msgs_Joy_h
#define _ROS_sensor_msgs_Joy_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class Joy : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<float> axes;
      std::vector<int32_t> buttons;

    Joy():
      header(),
      axes(),
      buttons()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->axes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->axes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->axes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->axes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < axes.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_axesi;
      u_axesi.real = this->axes[i];
      *(outbuffer + offset + 0) = (u_axesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_axesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_axesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_axesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->axes[i]);
      }
      *(outbuffer + offset + 0) = (this->buttons.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->buttons.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->buttons.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->buttons.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < buttons.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_buttonsi;
      u_buttonsi.real = this->buttons[i];
      *(outbuffer + offset + 0) = (u_buttonsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_buttonsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_buttonsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_buttonsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->buttons[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t axes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      axes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      axes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      axes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      axes.resize(axes_lengthT);
      for( uint32_t i = 0; i < axes.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_axesi;
      u_axesi.base = 0;
      u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->axes[i] = u_axesi.real;
      offset += sizeof(this->axes[i]);
      }
      uint32_t buttons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      buttons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      buttons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      buttons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      buttons.resize(buttons_lengthT);
      for( uint32_t i = 0; i < buttons.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_buttonsi;
      u_buttonsi.base = 0;
      u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->buttons[i] = u_buttonsi.real;
      offset += sizeof(this->buttons[i]);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Joy"; };
    const char * getMD5(){ return "5a9ea5f83505693b71e785041e67a8bb"; };

  };

}
#endif