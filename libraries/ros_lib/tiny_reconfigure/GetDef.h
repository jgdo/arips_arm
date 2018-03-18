#ifndef _ROS_tiny_reconfigure_GetDef_h
#define _ROS_tiny_reconfigure_GetDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tiny_reconfigure
{

  class GetDef : public ros::Msg
  {
    public:
      typedef uint8_t _cmd_type;
      _cmd_type cmd;
      typedef uint8_t _group_id_type;
      _group_id_type group_id;
      typedef uint8_t _param_id_type;
      _param_id_type param_id;
      enum { CMD_LIST_ALL =  1 };
      enum { CMD_LIST_GROUP_DEF =  2 };
      enum { CMD_GET_GROUP_DEF =  3 };
      enum { CMD_LIST_PARAM_DEF =  4 };
      enum { CMD_GET_PARAM_DEF =  5 };

    GetDef():
      cmd(0),
      group_id(0),
      param_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->cmd >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cmd);
      *(outbuffer + offset + 0) = (this->group_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->group_id);
      *(outbuffer + offset + 0) = (this->param_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->param_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->cmd =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cmd);
      this->group_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->group_id);
      this->param_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->param_id);
     return offset;
    }

    const char * getType(){ return "tiny_reconfigure/GetDef"; };
    const char * getMD5(){ return "c0b4ff473f11653c80dfd28af4a1629c"; };

  };

}
#endif