#ifndef _ROS_SERVICE_SelfTest_h
#define _ROS_SERVICE_SelfTest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "diagnostic_msgs/DiagnosticStatus.h"

namespace diagnostic_msgs
{

static const char SELFTEST[] = "diagnostic_msgs/SelfTest";

  class SelfTestRequest : public ros::Msg
  {
    public:

    SelfTestRequest()
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

    const char * getType(){ return SELFTEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SelfTestResponse : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef int8_t _passed_type;
      _passed_type passed;
      std::vector<diagnostic_msgs::DiagnosticStatus> status;

    SelfTestResponse():
      id(""),
      passed(0),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        int8_t real;
        uint8_t base;
      } u_passed;
      u_passed.real = this->passed;
      *(outbuffer + offset + 0) = (u_passed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passed);
      *(outbuffer + offset + 0) = (this->status.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < status.size(); i++){
      offset += this->status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        int8_t real;
        uint8_t base;
      } u_passed;
      u_passed.base = 0;
      u_passed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->passed = u_passed.real;
      offset += sizeof(this->passed);
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      status.resize(status_lengthT);
      for( uint32_t i = 0; i < status.size(); i++){
      offset += this->status[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return SELFTEST; };
    const char * getMD5(){ return "ac21b1bab7ab17546986536c22eb34e9"; };

  };

  class SelfTest {
    public:
    typedef SelfTestRequest Request;
    typedef SelfTestResponse Response;
  };

}
#endif
