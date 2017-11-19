#ifndef _ROS_SERVICE_Publishers_h
#define _ROS_SERVICE_Publishers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char PUBLISHERS[] = "rosapi/Publishers";

  class PublishersRequest : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;

    PublishersRequest():
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

    const char * getType(){ return PUBLISHERS; };
    const char * getMD5(){ return "d8f94bae31b356b24d0427f80426d0c3"; };

  };

  class PublishersResponse : public ros::Msg
  {
    public:
      std::vector<char*> publishers;

    PublishersResponse():
      publishers()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->publishers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->publishers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->publishers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->publishers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < publishers.size(); i++){
      uint32_t length_publishersi = strlen(this->publishers[i]);
      varToArr(outbuffer + offset, length_publishersi);
      offset += 4;
      memcpy(outbuffer + offset, this->publishers[i], length_publishersi);
      offset += length_publishersi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t publishers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      publishers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      publishers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      publishers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      publishers.resize(publishers_lengthT);
      for( uint32_t i = 0; i < publishers.size(); i++){
      uint32_t length_publishersi;
      arrToVar(length_publishersi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_publishersi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_publishersi-1]=0;
      this->publishers[i] = (char *)(inbuffer + offset-1);
      offset += length_publishersi;
      }
     return offset;
    }

    const char * getType(){ return PUBLISHERS; };
    const char * getMD5(){ return "167d8030c4ca4018261dff8ae5083dc8"; };

  };

  class Publishers {
    public:
    typedef PublishersRequest Request;
    typedef PublishersResponse Response;
  };

}
#endif
