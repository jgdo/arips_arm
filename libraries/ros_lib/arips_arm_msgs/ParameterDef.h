#ifndef _ROS_arips_arm_msgs_ParameterDef_h
#define _ROS_arips_arm_msgs_ParameterDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/ParameterType.h"

namespace arips_arm_msgs
{

  class ParameterDef : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef arips_arm_msgs::ParameterType _type_type;
      _type_type type;
      typedef int32_t _min_int_type;
      _min_int_type min_int;
      typedef int32_t _max_int_type;
      _max_int_type max_int;
      typedef int32_t _dfl_int_type;
      _dfl_int_type dfl_int;
      typedef int32_t _current_int_value_type;
      _current_int_value_type current_int_value;
      typedef float _min_double_type;
      _min_double_type min_double;
      typedef float _max_double_type;
      _max_double_type max_double;
      typedef float _dfl_double_type;
      _dfl_double_type dfl_double;
      typedef float _current_double_value_type;
      _current_double_value_type current_double_value;

    ParameterDef():
      name(""),
      type(),
      min_int(0),
      max_int(0),
      dfl_int(0),
      current_int_value(0),
      min_double(0),
      max_double(0),
      dfl_double(0),
      current_double_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->type.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_min_int;
      u_min_int.real = this->min_int;
      *(outbuffer + offset + 0) = (u_min_int.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_int.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_int.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_int.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_int);
      union {
        int32_t real;
        uint32_t base;
      } u_max_int;
      u_max_int.real = this->max_int;
      *(outbuffer + offset + 0) = (u_max_int.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_int.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_int.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_int.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_int);
      union {
        int32_t real;
        uint32_t base;
      } u_dfl_int;
      u_dfl_int.real = this->dfl_int;
      *(outbuffer + offset + 0) = (u_dfl_int.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dfl_int.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dfl_int.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dfl_int.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dfl_int);
      union {
        int32_t real;
        uint32_t base;
      } u_current_int_value;
      u_current_int_value.real = this->current_int_value;
      *(outbuffer + offset + 0) = (u_current_int_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_int_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_int_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_int_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_int_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_double);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_double);
      offset += serializeAvrFloat64(outbuffer + offset, this->dfl_double);
      offset += serializeAvrFloat64(outbuffer + offset, this->current_double_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->type.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_min_int;
      u_min_int.base = 0;
      u_min_int.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_int.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_int.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_int.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_int = u_min_int.real;
      offset += sizeof(this->min_int);
      union {
        int32_t real;
        uint32_t base;
      } u_max_int;
      u_max_int.base = 0;
      u_max_int.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_int.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_int.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_int.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_int = u_max_int.real;
      offset += sizeof(this->max_int);
      union {
        int32_t real;
        uint32_t base;
      } u_dfl_int;
      u_dfl_int.base = 0;
      u_dfl_int.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dfl_int.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dfl_int.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dfl_int.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dfl_int = u_dfl_int.real;
      offset += sizeof(this->dfl_int);
      union {
        int32_t real;
        uint32_t base;
      } u_current_int_value;
      u_current_int_value.base = 0;
      u_current_int_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_int_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_int_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_int_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_int_value = u_current_int_value.real;
      offset += sizeof(this->current_int_value);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_double));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_double));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dfl_double));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current_double_value));
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/ParameterDef"; };
    const char * getMD5(){ return "bfeabe78d60f3e4207507301872936d0"; };

  };

}
#endif