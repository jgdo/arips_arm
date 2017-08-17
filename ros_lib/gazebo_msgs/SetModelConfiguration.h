#ifndef _ROS_SERVICE_SetModelConfiguration_h
#define _ROS_SERVICE_SetModelConfiguration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace gazebo_msgs
{

static const char SETMODELCONFIGURATION[] = "gazebo_msgs/SetModelConfiguration";

  class SetModelConfigurationRequest : public ros::Msg
  {
    public:
      typedef const char* _model_name_type;
      _model_name_type model_name;
      typedef const char* _urdf_param_name_type;
      _urdf_param_name_type urdf_param_name;
      std::vector<char*> joint_names;
      std::vector<float> joint_positions;

    SetModelConfigurationRequest():
      model_name(""),
      urdf_param_name(""),
      joint_names(),
      joint_positions()
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
      uint32_t length_urdf_param_name = strlen(this->urdf_param_name);
      varToArr(outbuffer + offset, length_urdf_param_name);
      offset += 4;
      memcpy(outbuffer + offset, this->urdf_param_name, length_urdf_param_name);
      offset += length_urdf_param_name;
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
      *(outbuffer + offset + 0) = (this->joint_positions.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_positions.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_positions.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_positions.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < joint_positions.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_positions[i]);
      }
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
      uint32_t length_urdf_param_name;
      arrToVar(length_urdf_param_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_urdf_param_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_urdf_param_name-1]=0;
      this->urdf_param_name = (char *)(inbuffer + offset-1);
      offset += length_urdf_param_name;
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
      uint32_t joint_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      joint_positions.resize(joint_positions_lengthT);
      for( uint32_t i = 0; i < joint_positions.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_positions[i]));
      }
     return offset;
    }

    const char * getType(){ return SETMODELCONFIGURATION; };
    const char * getMD5(){ return "160eae60f51fabff255480c70afa289f"; };

  };

  class SetModelConfigurationResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_message_type;
      _status_message_type status_message;

    SetModelConfigurationResponse():
      success(0),
      status_message("")
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

    const char * getType(){ return SETMODELCONFIGURATION; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetModelConfiguration {
    public:
    typedef SetModelConfigurationRequest Request;
    typedef SetModelConfigurationResponse Response;
  };

}
#endif
