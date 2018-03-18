#ifndef _ROS_arips_arm_msgs_ParameterValue_h
#define _ROS_arips_arm_msgs_ParameterValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class ParameterValue : public ros::Msg
  {
    public:
      typedef uint16_t _group_id_type;
      _group_id_type group_id;
      typedef uint16_t _parameter_id_type;
      _parameter_id_type parameter_id;
      typedef int32_t _int_value_type;
      _int_value_type int_value;
      typedef float _double_value_type;
      _double_value_type double_value;

    ParameterValue():
      group_id(0),
      parameter_id(0),
      int_value(0),
      double_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->group_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->group_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->group_id);
      *(outbuffer + offset + 0) = (this->parameter_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameter_id >> (8 * 1)) & 0xFF;
      offset += sizeof(this->parameter_id);
      union {
        int32_t real;
        uint32_t base;
      } u_int_value;
      u_int_value.real = this->int_value;
      *(outbuffer + offset + 0) = (u_int_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_int_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_int_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->int_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->double_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->group_id =  ((uint16_t) (*(inbuffer + offset)));
      this->group_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->group_id);
      this->parameter_id =  ((uint16_t) (*(inbuffer + offset)));
      this->parameter_id |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->parameter_id);
      union {
        int32_t real;
        uint32_t base;
      } u_int_value;
      u_int_value.base = 0;
      u_int_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_int_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_int_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->int_value = u_int_value.real;
      offset += sizeof(this->int_value);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->double_value));
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/ParameterValue"; };
    const char * getMD5(){ return "1151d7ee1942e1750a3aae3f6cebd0c8"; };

  };

}
#endif