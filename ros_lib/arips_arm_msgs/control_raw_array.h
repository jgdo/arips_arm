#ifndef _ROS_arips_arm_msgs_control_raw_array_h
#define _ROS_arips_arm_msgs_control_raw_array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/control_raw_stamped.h"

namespace arips_arm_msgs
{

  class control_raw_array : public ros::Msg
  {
    public:
      arips_arm_msgs::control_raw_stamped data[64];

    control_raw_array():
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 64; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 64; i++){
      offset += this->data[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/control_raw_array"; };
    const char * getMD5(){ return "0a00546ab298c35dbc7efe7fbb855fe7"; };

  };

}
#endif