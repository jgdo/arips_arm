#ifndef _ROS_SERVICE_NodeletLoad_h
#define _ROS_SERVICE_NodeletLoad_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace nodelet
{

static const char NODELETLOAD[] = "nodelet/NodeletLoad";

  class NodeletLoadRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _type_type;
      _type_type type;
      std::vector<char*> remap_source_args;
      std::vector<char*> remap_target_args;
      std::vector<char*> my_argv;
      typedef const char* _bond_id_type;
      _bond_id_type bond_id;

    NodeletLoadRequest():
      name(""),
      type(""),
      remap_source_args(),
      remap_target_args(),
      my_argv(),
      bond_id("")
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
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->remap_source_args.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remap_source_args.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remap_source_args.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remap_source_args.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < remap_source_args.size(); i++){
      uint32_t length_remap_source_argsi = strlen(this->remap_source_args[i]);
      varToArr(outbuffer + offset, length_remap_source_argsi);
      offset += 4;
      memcpy(outbuffer + offset, this->remap_source_args[i], length_remap_source_argsi);
      offset += length_remap_source_argsi;
      }
      *(outbuffer + offset + 0) = (this->remap_target_args.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remap_target_args.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remap_target_args.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remap_target_args.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < remap_target_args.size(); i++){
      uint32_t length_remap_target_argsi = strlen(this->remap_target_args[i]);
      varToArr(outbuffer + offset, length_remap_target_argsi);
      offset += 4;
      memcpy(outbuffer + offset, this->remap_target_args[i], length_remap_target_argsi);
      offset += length_remap_target_argsi;
      }
      *(outbuffer + offset + 0) = (this->my_argv.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->my_argv.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->my_argv.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->my_argv.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < my_argv.size(); i++){
      uint32_t length_my_argvi = strlen(this->my_argv[i]);
      varToArr(outbuffer + offset, length_my_argvi);
      offset += 4;
      memcpy(outbuffer + offset, this->my_argv[i], length_my_argvi);
      offset += length_my_argvi;
      }
      uint32_t length_bond_id = strlen(this->bond_id);
      varToArr(outbuffer + offset, length_bond_id);
      offset += 4;
      memcpy(outbuffer + offset, this->bond_id, length_bond_id);
      offset += length_bond_id;
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
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t remap_source_args_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      remap_source_args_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      remap_source_args_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      remap_source_args_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      remap_source_args.resize(remap_source_args_lengthT);
      for( uint32_t i = 0; i < remap_source_args.size(); i++){
      uint32_t length_remap_source_argsi;
      arrToVar(length_remap_source_argsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_remap_source_argsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_remap_source_argsi-1]=0;
      this->remap_source_args[i] = (char *)(inbuffer + offset-1);
      offset += length_remap_source_argsi;
      }
      uint32_t remap_target_args_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      remap_target_args_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      remap_target_args_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      remap_target_args_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      remap_target_args.resize(remap_target_args_lengthT);
      for( uint32_t i = 0; i < remap_target_args.size(); i++){
      uint32_t length_remap_target_argsi;
      arrToVar(length_remap_target_argsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_remap_target_argsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_remap_target_argsi-1]=0;
      this->remap_target_args[i] = (char *)(inbuffer + offset-1);
      offset += length_remap_target_argsi;
      }
      uint32_t my_argv_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      my_argv_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      my_argv_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      my_argv_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      my_argv.resize(my_argv_lengthT);
      for( uint32_t i = 0; i < my_argv.size(); i++){
      uint32_t length_my_argvi;
      arrToVar(length_my_argvi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_my_argvi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_my_argvi-1]=0;
      this->my_argv[i] = (char *)(inbuffer + offset-1);
      offset += length_my_argvi;
      }
      uint32_t length_bond_id;
      arrToVar(length_bond_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_bond_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_bond_id-1]=0;
      this->bond_id = (char *)(inbuffer + offset-1);
      offset += length_bond_id;
     return offset;
    }

    const char * getType(){ return NODELETLOAD; };
    const char * getMD5(){ return "c6e28cc4d2e259249d96cfb50658fbec"; };

  };

  class NodeletLoadResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    NodeletLoadResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return NODELETLOAD; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class NodeletLoad {
    public:
    typedef NodeletLoadRequest Request;
    typedef NodeletLoadResponse Response;
  };

}
#endif
