#ifndef _ROS_SERVICE_SetParam_h
#define _ROS_SERVICE_SetParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tiny_reconfigure
{

static const char SETPARAM[] = "tiny_reconfigure/SetParam";

  class SetParamRequest : public ros::Msg
  {
    public:
      typedef uint8_t _group_id_type;
      _group_id_type group_id;
      typedef uint8_t _param_id_type;
      _param_id_type param_id;
      typedef int32_t _value_int_type;
      _value_int_type value_int;
      typedef float _value_float_type;
      _value_float_type value_float;

    SetParamRequest():
      group_id(0),
      param_id(0),
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

    const char * getType(){ return SETPARAM; };
    const char * getMD5(){ return "44033cdf5fea2a20446563888d2f0d54"; };

  };

  class SetParamResponse : public ros::Msg
  {
    public:
      typedef uint8_t _result_type;
      _result_type result;
      typedef int32_t _value_int_type;
      _value_int_type value_int;
      typedef float _value_float_type;
      _value_float_type value_float;

    SetParamResponse():
      result(0),
      value_int(0),
      value_float(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->result >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
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
      this->result =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->result);
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

    const char * getType(){ return SETPARAM; };
    const char * getMD5(){ return "e435b7fbe7ec8991130b74a1011b6fb5"; };

  };

  class SetParam {
    public:
    typedef SetParamRequest Request;
    typedef SetParamResponse Response;
  };

}
#endif
