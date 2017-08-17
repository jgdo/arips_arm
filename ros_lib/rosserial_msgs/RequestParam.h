#ifndef _ROS_SERVICE_RequestParam_h
#define _ROS_SERVICE_RequestParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosserial_msgs
{

static const char REQUESTPARAM[] = "rosserial_msgs/RequestParam";

  class RequestParamRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;

    RequestParamRequest():
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    const char * getType(){ return REQUESTPARAM; };
    const char * getMD5(){ return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class RequestParamResponse : public ros::Msg
  {
    public:
      std::vector<int32_t> ints;
      std::vector<float> floats;
      std::vector<char*> strings;

    RequestParamResponse():
      ints(),
      floats(),
      strings()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < ints.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_intsi;
      u_intsi.real = this->ints[i];
      *(outbuffer + offset + 0) = (u_intsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ints[i]);
      }
      *(outbuffer + offset + 0) = (this->floats.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->floats.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->floats.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->floats.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < floats.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_floatsi;
      u_floatsi.real = this->floats[i];
      *(outbuffer + offset + 0) = (u_floatsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_floatsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_floatsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_floatsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->floats[i]);
      }
      *(outbuffer + offset + 0) = (this->strings.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->strings.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->strings.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->strings.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < strings.size(); i++){
      uint32_t length_stringsi = strlen(this->strings[i]);
      varToArr(outbuffer + offset, length_stringsi);
      offset += 4;
      memcpy(outbuffer + offset, this->strings[i], length_stringsi);
      offset += length_stringsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t ints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      ints.resize(ints_lengthT);
      for( uint32_t i = 0; i < ints.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_intsi;
      u_intsi.base = 0;
      u_intsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ints[i] = u_intsi.real;
      offset += sizeof(this->ints[i]);
      }
      uint32_t floats_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      floats_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      floats_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      floats_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      floats.resize(floats_lengthT);
      for( uint32_t i = 0; i < floats.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_floatsi;
      u_floatsi.base = 0;
      u_floatsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_floatsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_floatsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_floatsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->floats[i] = u_floatsi.real;
      offset += sizeof(this->floats[i]);
      }
      uint32_t strings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      strings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      strings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      strings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      strings.resize(strings_lengthT);
      for( uint32_t i = 0; i < strings.size(); i++){
      uint32_t length_stringsi;
      arrToVar(length_stringsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_stringsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_stringsi-1]=0;
      this->strings[i] = (char *)(inbuffer + offset-1);
      offset += length_stringsi;
      }
     return offset;
    }

    const char * getType(){ return REQUESTPARAM; };
    const char * getMD5(){ return "9f0e98bda65981986ddf53afa7a40e49"; };

  };

  class RequestParam {
    public:
    typedef RequestParamRequest Request;
    typedef RequestParamResponse Response;
  };

}
#endif
