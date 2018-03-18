#ifndef _ROS_SERVICE_GetParameterGroupDef_h
#define _ROS_SERVICE_GetParameterGroupDef_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/ParameterDef.h"

namespace arips_arm_msgs
{

static const char GETPARAMETERGROUPDEF[] = "arips_arm_msgs/GetParameterGroupDef";

  class GetParameterGroupDefRequest : public ros::Msg
  {
    public:
      typedef uint16_t _group_id_type;
      _group_id_type group_id;

    GetParameterGroupDefRequest():
      group_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->group_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->group_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->group_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->group_id =  ((uint16_t) (*(inbuffer + offset)));
      this->group_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->group_id);
     return offset;
    }

    const char * getType(){ return GETPARAMETERGROUPDEF; };
    const char * getMD5(){ return "e97fcf6762ccabd2161b4953582c462a"; };

  };

  class GetParameterGroupDefResponse : public ros::Msg
  {
    public:
      uint32_t param_defs_length;
      typedef arips_arm_msgs::ParameterDef _param_defs_type;
      _param_defs_type st_param_defs;
      _param_defs_type * param_defs;

    GetParameterGroupDefResponse():
      param_defs_length(0), param_defs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->param_defs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->param_defs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->param_defs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->param_defs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->param_defs_length);
      for( uint32_t i = 0; i < param_defs_length; i++){
      offset += this->param_defs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t param_defs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      param_defs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      param_defs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      param_defs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->param_defs_length);
      if(param_defs_lengthT > param_defs_length)
        this->param_defs = (arips_arm_msgs::ParameterDef*)realloc(this->param_defs, param_defs_lengthT * sizeof(arips_arm_msgs::ParameterDef));
      param_defs_length = param_defs_lengthT;
      for( uint32_t i = 0; i < param_defs_length; i++){
      offset += this->st_param_defs.deserialize(inbuffer + offset);
        memcpy( &(this->param_defs[i]), &(this->st_param_defs), sizeof(arips_arm_msgs::ParameterDef));
      }
     return offset;
    }

    const char * getType(){ return GETPARAMETERGROUPDEF; };
    const char * getMD5(){ return "6e6e46e0d21a029f3e1ab6c21c81ef8c"; };

  };

  class GetParameterGroupDef {
    public:
    typedef GetParameterGroupDefRequest Request;
    typedef GetParameterGroupDefResponse Response;
  };

}
#endif
