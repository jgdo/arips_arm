#ifndef _ROS_SERVICE_ServiceProviders_h
#define _ROS_SERVICE_ServiceProviders_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char SERVICEPROVIDERS[] = "rosapi/ServiceProviders";

  class ServiceProvidersRequest : public ros::Msg
  {
    public:
      typedef const char* _service_type;
      _service_type service;

    ServiceProvidersRequest():
      service("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_service = strlen(this->service);
      varToArr(outbuffer + offset, length_service);
      offset += 4;
      memcpy(outbuffer + offset, this->service, length_service);
      offset += length_service;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_service;
      arrToVar(length_service, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service-1]=0;
      this->service = (char *)(inbuffer + offset-1);
      offset += length_service;
     return offset;
    }

    const char * getType(){ return SERVICEPROVIDERS; };
    const char * getMD5(){ return "1cbcfa13b08f6d36710b9af8741e6112"; };

  };

  class ServiceProvidersResponse : public ros::Msg
  {
    public:
      std::vector<char*> providers;

    ServiceProvidersResponse():
      providers()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->providers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->providers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->providers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->providers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < providers.size(); i++){
      uint32_t length_providersi = strlen(this->providers[i]);
      varToArr(outbuffer + offset, length_providersi);
      offset += 4;
      memcpy(outbuffer + offset, this->providers[i], length_providersi);
      offset += length_providersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t providers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      providers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      providers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      providers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      providers.resize(providers_lengthT);
      for( uint32_t i = 0; i < providers.size(); i++){
      uint32_t length_providersi;
      arrToVar(length_providersi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_providersi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_providersi-1]=0;
      this->providers[i] = (char *)(inbuffer + offset-1);
      offset += length_providersi;
      }
     return offset;
    }

    const char * getType(){ return SERVICEPROVIDERS; };
    const char * getMD5(){ return "945f6849f44f061c178ab393b12c1358"; };

  };

  class ServiceProviders {
    public:
    typedef ServiceProvidersRequest Request;
    typedef ServiceProvidersResponse Response;
  };

}
#endif
