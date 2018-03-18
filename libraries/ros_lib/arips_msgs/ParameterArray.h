#ifndef _ROS_arips_msgs_ParameterArray_h
#define _ROS_arips_msgs_ParameterArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_msgs/Parameter.h"

namespace arips_msgs
{

  class ParameterArray : public ros::Msg
  {
    public:
      uint32_t parameters_length;
      typedef arips_msgs::Parameter _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;

    ParameterArray():
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
        this->parameters = (arips_msgs::Parameter*)realloc(this->parameters, parameters_lengthT * sizeof(arips_msgs::Parameter));
      parameters_length = parameters_lengthT;
      for( uint32_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(arips_msgs::Parameter));
      }
     return offset;
    }

    const char * getType(){ return "arips_msgs/ParameterArray"; };
    const char * getMD5(){ return "c4b54e13b7c18e2c13c38c7a12d418c2"; };

  };

}
#endif