#ifndef _ROS_arips_arm_msgs_ParameterType_h
#define _ROS_arips_arm_msgs_ParameterType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class ParameterType : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      enum { TYPE_INT =  1 };
      enum { TYPE_DOUBLE =  2 };

    ParameterType():
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/ParameterType"; };
    const char * getMD5(){ return "06b139676f28f678a85bf193536466b2"; };

  };

}
#endif