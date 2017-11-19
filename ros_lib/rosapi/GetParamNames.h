#ifndef _ROS_SERVICE_GetParamNames_h
#define _ROS_SERVICE_GetParamNames_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char GETPARAMNAMES[] = "rosapi/GetParamNames";

  class GetParamNamesRequest : public ros::Msg
  {
    public:

    GetParamNamesRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETPARAMNAMES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetParamNamesResponse : public ros::Msg
  {
    public:
      std::vector<char*> names;

    GetParamNamesResponse():
      names()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < names.size(); i++){
      uint32_t length_namesi = strlen(this->names[i]);
      varToArr(outbuffer + offset, length_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      names.resize(names_lengthT);
      for( uint32_t i = 0; i < names.size(); i++){
      uint32_t length_namesi;
      arrToVar(length_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namesi-1]=0;
      this->names[i] = (char *)(inbuffer + offset-1);
      offset += length_namesi;
      }
     return offset;
    }

    const char * getType(){ return GETPARAMNAMES; };
    const char * getMD5(){ return "dc7ae3609524b18034e49294a4ce670e"; };

  };

  class GetParamNames {
    public:
    typedef GetParamNamesRequest Request;
    typedef GetParamNamesResponse Response;
  };

}
#endif