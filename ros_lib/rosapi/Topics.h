#ifndef _ROS_SERVICE_Topics_h
#define _ROS_SERVICE_Topics_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char TOPICS[] = "rosapi/Topics";

  class TopicsRequest : public ros::Msg
  {
    public:

    TopicsRequest()
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

    const char * getType(){ return TOPICS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TopicsResponse : public ros::Msg
  {
    public:
      std::vector<char*> topics;
      std::vector<char*> types;

    TopicsResponse():
      topics(),
      types()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->topics.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topics.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topics.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topics.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < topics.size(); i++){
      uint32_t length_topicsi = strlen(this->topics[i]);
      varToArr(outbuffer + offset, length_topicsi);
      offset += 4;
      memcpy(outbuffer + offset, this->topics[i], length_topicsi);
      offset += length_topicsi;
      }
      *(outbuffer + offset + 0) = (this->types.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->types.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->types.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->types.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < types.size(); i++){
      uint32_t length_typesi = strlen(this->types[i]);
      varToArr(outbuffer + offset, length_typesi);
      offset += 4;
      memcpy(outbuffer + offset, this->types[i], length_typesi);
      offset += length_typesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t topics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      topics.resize(topics_lengthT);
      for( uint32_t i = 0; i < topics.size(); i++){
      uint32_t length_topicsi;
      arrToVar(length_topicsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topicsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topicsi-1]=0;
      this->topics[i] = (char *)(inbuffer + offset-1);
      offset += length_topicsi;
      }
      uint32_t types_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      types_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      types_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      types_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      types.resize(types_lengthT);
      for( uint32_t i = 0; i < types.size(); i++){
      uint32_t length_typesi;
      arrToVar(length_typesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_typesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_typesi-1]=0;
      this->types[i] = (char *)(inbuffer + offset-1);
      offset += length_typesi;
      }
     return offset;
    }

    const char * getType(){ return TOPICS; };
    const char * getMD5(){ return "d966d98fc333fa1f3135af765eac1ba8"; };

  };

  class Topics {
    public:
    typedef TopicsRequest Request;
    typedef TopicsResponse Response;
  };

}
#endif
