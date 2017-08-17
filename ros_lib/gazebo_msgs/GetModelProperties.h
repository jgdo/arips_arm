#ifndef _ROS_SERVICE_GetModelProperties_h
#define _ROS_SERVICE_GetModelProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace gazebo_msgs
{

static const char GETMODELPROPERTIES[] = "gazebo_msgs/GetModelProperties";

  class GetModelPropertiesRequest : public ros::Msg
  {
    public:
      typedef const char* _model_name_type;
      _model_name_type model_name;

    GetModelPropertiesRequest():
      model_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_name = strlen(this->model_name);
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
     return offset;
    }

    const char * getType(){ return GETMODELPROPERTIES; };
    const char * getMD5(){ return "ea31c8eab6fc401383cf528a7c0984ba"; };

  };

  class GetModelPropertiesResponse : public ros::Msg
  {
    public:
      typedef const char* _parent_model_name_type;
      _parent_model_name_type parent_model_name;
      typedef const char* _canonical_body_name_type;
      _canonical_body_name_type canonical_body_name;
      std::vector<char*> body_names;
      std::vector<char*> geom_names;
      std::vector<char*> joint_names;
      std::vector<char*> child_model_names;
      typedef bool _is_static_type;
      _is_static_type is_static;
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_message_type;
      _status_message_type status_message;

    GetModelPropertiesResponse():
      parent_model_name(""),
      canonical_body_name(""),
      body_names(),
      geom_names(),
      joint_names(),
      child_model_names(),
      is_static(0),
      success(0),
      status_message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_parent_model_name = strlen(this->parent_model_name);
      varToArr(outbuffer + offset, length_parent_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->parent_model_name, length_parent_model_name);
      offset += length_parent_model_name;
      uint32_t length_canonical_body_name = strlen(this->canonical_body_name);
      varToArr(outbuffer + offset, length_canonical_body_name);
      offset += 4;
      memcpy(outbuffer + offset, this->canonical_body_name, length_canonical_body_name);
      offset += length_canonical_body_name;
      *(outbuffer + offset + 0) = (this->body_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->body_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->body_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->body_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < body_names.size(); i++){
      uint32_t length_body_namesi = strlen(this->body_names[i]);
      varToArr(outbuffer + offset, length_body_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->body_names[i], length_body_namesi);
      offset += length_body_namesi;
      }
      *(outbuffer + offset + 0) = (this->geom_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->geom_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->geom_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->geom_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < geom_names.size(); i++){
      uint32_t length_geom_namesi = strlen(this->geom_names[i]);
      varToArr(outbuffer + offset, length_geom_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->geom_names[i], length_geom_namesi);
      offset += length_geom_namesi;
      }
      *(outbuffer + offset + 0) = (this->joint_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < joint_names.size(); i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->child_model_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->child_model_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->child_model_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->child_model_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < child_model_names.size(); i++){
      uint32_t length_child_model_namesi = strlen(this->child_model_names[i]);
      varToArr(outbuffer + offset, length_child_model_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->child_model_names[i], length_child_model_namesi);
      offset += length_child_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_is_static;
      u_is_static.real = this->is_static;
      *(outbuffer + offset + 0) = (u_is_static.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_static);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = strlen(this->status_message);
      varToArr(outbuffer + offset, length_status_message);
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_parent_model_name;
      arrToVar(length_parent_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parent_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parent_model_name-1]=0;
      this->parent_model_name = (char *)(inbuffer + offset-1);
      offset += length_parent_model_name;
      uint32_t length_canonical_body_name;
      arrToVar(length_canonical_body_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_canonical_body_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_canonical_body_name-1]=0;
      this->canonical_body_name = (char *)(inbuffer + offset-1);
      offset += length_canonical_body_name;
      uint32_t body_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      body_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      body_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      body_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      body_names.resize(body_names_lengthT);
      for( uint32_t i = 0; i < body_names.size(); i++){
      uint32_t length_body_namesi;
      arrToVar(length_body_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_body_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_body_namesi-1]=0;
      this->body_names[i] = (char *)(inbuffer + offset-1);
      offset += length_body_namesi;
      }
      uint32_t geom_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      geom_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      geom_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      geom_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      geom_names.resize(geom_names_lengthT);
      for( uint32_t i = 0; i < geom_names.size(); i++){
      uint32_t length_geom_namesi;
      arrToVar(length_geom_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_geom_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_geom_namesi-1]=0;
      this->geom_names[i] = (char *)(inbuffer + offset-1);
      offset += length_geom_namesi;
      }
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      joint_names.resize(joint_names_lengthT);
      for( uint32_t i = 0; i < joint_names.size(); i++){
      uint32_t length_joint_namesi;
      arrToVar(length_joint_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_namesi-1]=0;
      this->joint_names[i] = (char *)(inbuffer + offset-1);
      offset += length_joint_namesi;
      }
      uint32_t child_model_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      child_model_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      child_model_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      child_model_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      child_model_names.resize(child_model_names_lengthT);
      for( uint32_t i = 0; i < child_model_names.size(); i++){
      uint32_t length_child_model_namesi;
      arrToVar(length_child_model_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_child_model_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_child_model_namesi-1]=0;
      this->child_model_names[i] = (char *)(inbuffer + offset-1);
      offset += length_child_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_is_static;
      u_is_static.base = 0;
      u_is_static.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_static = u_is_static.real;
      offset += sizeof(this->is_static);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      arrToVar(length_status_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
     return offset;
    }

    const char * getType(){ return GETMODELPROPERTIES; };
    const char * getMD5(){ return "b7f370938ef77b464b95f1bab3ec5028"; };

  };

  class GetModelProperties {
    public:
    typedef GetModelPropertiesRequest Request;
    typedef GetModelPropertiesResponse Response;
  };

}
#endif
