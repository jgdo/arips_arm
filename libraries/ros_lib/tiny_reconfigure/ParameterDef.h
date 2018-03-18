#ifndef _ROS_tiny_reconfigure_ParameterDef_h
#define _ROS_tiny_reconfigure_ParameterDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tiny_reconfigure
{

  class ParameterDef : public ros::Msg
  {
    public:
      typedef uint8_t _group_id_type;
      _group_id_type group_id;
      typedef uint8_t _param_id_type;
      _param_id_type param_id;
      typedef uint8_t _num_params_type;
      _num_params_type num_params;
      typedef const char* _param_name_type;
      _param_name_type param_name;
      typedef uint8_t _type_type;
      _type_type type;
      typedef int32_t _value_int_type;
      _value_int_type value_int;
      typedef float _value_float_type;
      _value_float_type value_float;
      enum { TYPE_INT =  1 };
      enum { TYPE_FLOAT =  2 };

    ParameterDef():
      group_id(0),
      param_id(0),
      num_params(0),
      param_name(""),
      type(0),
      value_int(0),
      value_float(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->group_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->group_id);
      *(outbuffer + offset + 0) = (this->param_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->param_id);
      *(outbuffer + offset + 0) = (this->num_params >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_params);
      uint32_t length_param_name = strlen(this->param_name);
      varToArr(outbuffer + offset, length_param_name);
      offset += 4;
      memcpy(outbuffer + offset, this->param_name, length_param_name);
      offset += length_param_name;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_value_int;
      u_value_int.real = this->value_int;
      *(outbuffer + offset + 0) = (u_value_int.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value_int.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value_int.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value_int.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_int);
      union {
        float real;
        uint32_t base;
      } u_value_float;
      u_value_float.real = this->value_float;
      *(outbuffer + offset + 0) = (u_value_float.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value_float.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value_float.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value_float.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_float);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->group_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->group_id);
      this->param_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->param_id);
      this->num_params =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_params);
      uint32_t length_param_name;
      arrToVar(length_param_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_param_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_param_name-1]=0;
      this->param_name = (char *)(inbuffer + offset-1);
      offset += length_param_name;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_value_int;
      u_value_int.base = 0;
      u_value_int.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value_int.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value_int.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value_int.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value_int = u_value_int.real;
      offset += sizeof(this->value_int);
      union {
        float real;
        uint32_t base;
      } u_value_float;
      u_value_float.base = 0;
      u_value_float.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value_float.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value_float.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value_float.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value_float = u_value_float.real;
      offset += sizeof(this->value_float);
     return offset;
    }

    const char * getType(){ return "tiny_reconfigure/ParameterDef"; };
    const char * getMD5(){ return "e35186613ceb40cd7e1d32f682a6c091"; };

  };

}
#endif