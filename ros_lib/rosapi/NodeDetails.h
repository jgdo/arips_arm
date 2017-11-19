#ifndef _ROS_SERVICE_NodeDetails_h
#define _ROS_SERVICE_NodeDetails_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char NODEDETAILS[] = "rosapi/NodeDetails";

  class NodeDetailsRequest : public ros::Msg
  {
    public:
      typedef const char* _node_type;
      _node_type node;

    NodeDetailsRequest():
      node("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_node = strlen(this->node);
      varToArr(outbuffer + offset, length_node);
      offset += 4;
      memcpy(outbuffer + offset, this->node, length_node);
      offset += length_node;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_node;
      arrToVar(length_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node-1]=0;
      this->node = (char *)(inbuffer + offset-1);
      offset += length_node;
     return offset;
    }

    const char * getType(){ return NODEDETAILS; };
    const char * getMD5(){ return "a94c40e70a4b82863e6e52ec16732447"; };

  };

  class NodeDetailsResponse : public ros::Msg
  {
    public:
      std::vector<char*> subscribing;
      std::vector<char*> publishing;
      std::vector<char*> services;

    NodeDetailsResponse():
      subscribing(),
      publishing(),
      services()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->subscribing.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subscribing.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subscribing.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subscribing.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < subscribing.size(); i++){
      uint32_t length_subscribingi = strlen(this->subscribing[i]);
      varToArr(outbuffer + offset, length_subscribingi);
      offset += 4;
      memcpy(outbuffer + offset, this->subscribing[i], length_subscribingi);
      offset += length_subscribingi;
      }
      *(outbuffer + offset + 0) = (this->publishing.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->publishing.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->publishing.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->publishing.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < publishing.size(); i++){
      uint32_t length_publishingi = strlen(this->publishing[i]);
      varToArr(outbuffer + offset, length_publishingi);
      offset += 4;
      memcpy(outbuffer + offset, this->publishing[i], length_publishingi);
      offset += length_publishingi;
      }
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
      uint32_t subscribing_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subscribing_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subscribing_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subscribing_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      subscribing.resize(subscribing_lengthT);
      for( uint32_t i = 0; i < subscribing.size(); i++){
      uint32_t length_subscribingi;
      arrToVar(length_subscribingi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subscribingi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subscribingi-1]=0;
      this->subscribing[i] = (char *)(inbuffer + offset-1);
      offset += length_subscribingi;
      }
      uint32_t publishing_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      publishing_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      publishing_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      publishing_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      publishing.resize(publishing_lengthT);
      for( uint32_t i = 0; i < publishing.size(); i++){
      uint32_t length_publishingi;
      arrToVar(length_publishingi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_publishingi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_publishingi-1]=0;
      this->publishing[i] = (char *)(inbuffer + offset-1);
      offset += length_publishingi;
      }
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

    const char * getType(){ return NODEDETAILS; };
    const char * getMD5(){ return "3da1cb16c6ec5885ad291735b6244a48"; };

  };

  class NodeDetails {
    public:
    typedef NodeDetailsRequest Request;
    typedef NodeDetailsResponse Response;
  };

}
#endif
