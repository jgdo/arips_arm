#ifndef _ROS_SERVICE_SetParameter_h
#define _ROS_SERVICE_SetParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/ParameterValue.h"

namespace arips_arm_msgs
{

static const char SETPARAMETER[] = "arips_arm_msgs/SetParameter";

  class SetParameterRequest : public ros::Msg
  {
    public:
      uint32_t parameters_length;
      typedef arips_arm_msgs::ParameterValue _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;

    SetParameterRequest():
      parameters_length(0), parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameters_length);
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parameters_length);
      if(parameters_lengthT > parameters_length)
        this->parameters = (arips_arm_msgs::ParameterValue*)realloc(this->parameters, parameters_lengthT * sizeof(arips_arm_msgs::ParameterValue));
      parameters_length = parameters_lengthT;
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(arips_arm_msgs::ParameterValue));
      }
     return offset;
    }

    const char * getType(){ return SETPARAMETER; };
    const char * getMD5(){ return "134439a8f88dbe5e31384f2c0eca198c"; };

  };

  class SetParameterResponse : public ros::Msg
  {
    public:
      typedef uint8_t _result_type;
      _result_type result;

    SetParameterResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->result >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->result =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SETPARAMETER; };
    const char * getMD5(){ return "25458147911545c320c4c0a299eff763"; };

  };

  class SetParameter {
    public:
    typedef SetParameterRequest Request;
    typedef SetParameterResponse Response;
  };

}
#endif
