#ifndef _ROS_SERVICE_Services_h
#define _ROS_SERVICE_Services_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char SERVICES[] = "rosapi/Services";

  class ServicesRequest : public ros::Msg
  {
    public:

    ServicesRequest()
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

    const char * getType(){ return SERVICES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ServicesResponse : public ros::Msg
  {
    public:
      std::vector<char*> services;

    ServicesResponse():
      services()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->services.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->services.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->services.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->services.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < services.size(); i++){
      uint32_t length_servicesi = strlen(this->services[i]);
      varToArr(outbuffer + offset, length_servicesi);
      offset += 4;
      memcpy(outbuffer + offset, this->services[i], length_servicesi);
      offset += length_servicesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t services_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      services_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      services_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      services_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      services.resize(services_lengthT);
      for( uint32_t i = 0; i < services.size(); i++){
      uint32_t length_servicesi;
      arrToVar(length_servicesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_servicesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_servicesi-1]=0;
      this->services[i] = (char *)(inbuffer + offset-1);
      offset += length_servicesi;
      }
     return offset;
    }

    const char * getType(){ return SERVICES; };
    const char * getMD5(){ return "e44a7e7bcb900acadbcc28b132378f0c"; };

  };

  class Services {
    public:
    typedef ServicesRequest Request;
    typedef ServicesResponse Response;
  };

}
#endif
