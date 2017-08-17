#ifndef _ROS_SERVICE_SetParameter_h
#define _ROS_SERVICE_SetParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace arips_arm_msgs
{

static const char SETPARAMETER[] = "arips_arm_msgs/SetParameter";

  class SetParameterRequest : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _value_type;
      _value_type value;

    SetParameterRequest():
      id(0),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    const char * getType(){ return SETPARAMETER; };
    const char * getMD5(){ return "5db66e017a38027f2e35368c71ea670c"; };

  };

  class SetParameterResponse : public ros::Msg
  {
    public:
      typedef uint32_t _result_type;
      _result_type result;

    SetParameterResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->result >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->result >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->result >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->result >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->result =  ((uint32_t) (*(inbuffer + offset)));
      this->result |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->result |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->result |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SETPARAMETER; };
    const char * getMD5(){ return "13d5d28ceaaadbc975dd072a2e10b88a"; };

  };

  class SetParameter {
    public:
    typedef SetParameterRequest Request;
    typedef SetParameterResponse Response;
  };

}
#endif
