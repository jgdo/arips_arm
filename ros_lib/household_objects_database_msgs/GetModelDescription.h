#ifndef _ROS_SERVICE_GetModelDescription_h
#define _ROS_SERVICE_GetModelDescription_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseReturnCode.h"

namespace household_objects_database_msgs
{

static const char GETMODELDESCRIPTION[] = "household_objects_database_msgs/GetModelDescription";

  class GetModelDescriptionRequest : public ros::Msg
  {
    public:
      typedef int32_t _model_id_type;
      _model_id_type model_id;

    GetModelDescriptionRequest():
      model_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_model_id;
      u_model_id.real = this->model_id;
      *(outbuffer + offset + 0) = (u_model_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_model_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_model_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_model_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->model_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_model_id;
      u_model_id.base = 0;
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->model_id = u_model_id.real;
      offset += sizeof(this->model_id);
     return offset;
    }

    const char * getType(){ return GETMODELDESCRIPTION; };
    const char * getMD5(){ return "28cb0598daf3b969068a38cd07aaa9f6"; };

  };

  class GetModelDescriptionResponse : public ros::Msg
  {
    public:
      typedef household_objects_database_msgs::DatabaseReturnCode _return_code_type;
      _return_code_type return_code;
      std::vector<char*> tags;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _maker_type;
      _maker_type maker;

    GetModelDescriptionResponse():
      return_code(),
      tags(),
      name(""),
      maker("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->return_code.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tags.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < tags.size(); i++){
      uint32_t length_tagsi = strlen(this->tags[i]);
      varToArr(outbuffer + offset, length_tagsi);
      offset += 4;
      memcpy(outbuffer + offset, this->tags[i], length_tagsi);
      offset += length_tagsi;
      }
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_maker = strlen(this->maker);
      varToArr(outbuffer + offset, length_maker);
      offset += 4;
      memcpy(outbuffer + offset, this->maker, length_maker);
      offset += length_maker;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->return_code.deserialize(inbuffer + offset);
      uint32_t tags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      tags.resize(tags_lengthT);
      for( uint32_t i = 0; i < tags.size(); i++){
      uint32_t length_tagsi;
      arrToVar(length_tagsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tagsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tagsi-1]=0;
      this->tags[i] = (char *)(inbuffer + offset-1);
      offset += length_tagsi;
      }
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_maker;
      arrToVar(length_maker, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_maker; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_maker-1]=0;
      this->maker = (char *)(inbuffer + offset-1);
      offset += length_maker;
     return offset;
    }

    const char * getType(){ return GETMODELDESCRIPTION; };
    const char * getMD5(){ return "e6c55e34b143695104d37ad9b33c72c0"; };

  };

  class GetModelDescription {
    public:
    typedef GetModelDescriptionRequest Request;
    typedef GetModelDescriptionResponse Response;
  };

}
#endif
