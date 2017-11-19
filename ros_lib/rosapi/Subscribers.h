#ifndef _ROS_SERVICE_Subscribers_h
#define _ROS_SERVICE_Subscribers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char SUBSCRIBERS[] = "rosapi/Subscribers";

  class SubscribersRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    SubscribersRequest():
      topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
     return offset;
    }

    const char * getType(){ return SUBSCRIBERS; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class SubscribersResponse : public ros::Msg
  {
    public:
      std::vector<char*> subscribers;

    SubscribersResponse():
      subscribers()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->subscribers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subscribers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subscribers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subscribers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < subscribers.size(); i++){
      uint32_t length_subscribersi = strlen(this->subscribers[i]);
      varToArr(outbuffer + offset, length_subscribersi);
      offset += 4;
      memcpy(outbuffer + offset, this->subscribers[i], length_subscribersi);
      offset += length_subscribersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t subscribers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subscribers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subscribers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subscribers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      subscribers.resize(subscribers_lengthT);
      for( uint32_t i = 0; i < subscribers.size(); i++){
      uint32_t length_subscribersi;
      arrToVar(length_subscribersi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subscribersi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subscribersi-1]=0;
      this->subscribers[i] = (char *)(inbuffer + offset-1);
      offset += length_subscribersi;
      }
     return offset;
    }

    const char * getType(){ return SUBSCRIBERS; };
    const char * getMD5(){ return "22418cab5ba9531d8c2b738b4e56153b"; };

  };

  class Subscribers {
    public:
    typedef SubscribersRequest Request;
    typedef SubscribersResponse Response;
  };

}
#endif
