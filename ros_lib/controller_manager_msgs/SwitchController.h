#ifndef _ROS_SERVICE_SwitchController_h
#define _ROS_SERVICE_SwitchController_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace controller_manager_msgs
{

static const char SWITCHCONTROLLER[] = "controller_manager_msgs/SwitchController";

  class SwitchControllerRequest : public ros::Msg
  {
    public:
      std::vector<char*> start_controllers;
      std::vector<char*> stop_controllers;
      typedef int32_t _strictness_type;
      _strictness_type strictness;
      enum { BEST_EFFORT = 1 };
      enum { STRICT = 2 };

    SwitchControllerRequest():
      start_controllers(),
      stop_controllers(),
      strictness(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->start_controllers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_controllers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_controllers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_controllers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < start_controllers.size(); i++){
      uint32_t length_start_controllersi = strlen(this->start_controllers[i]);
      varToArr(outbuffer + offset, length_start_controllersi);
      offset += 4;
      memcpy(outbuffer + offset, this->start_controllers[i], length_start_controllersi);
      offset += length_start_controllersi;
      }
      *(outbuffer + offset + 0) = (this->stop_controllers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_controllers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_controllers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_controllers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < stop_controllers.size(); i++){
      uint32_t length_stop_controllersi = strlen(this->stop_controllers[i]);
      varToArr(outbuffer + offset, length_stop_controllersi);
      offset += 4;
      memcpy(outbuffer + offset, this->stop_controllers[i], length_stop_controllersi);
      offset += length_stop_controllersi;
      }
      union {
        int32_t real;
        uint32_t base;
      } u_strictness;
      u_strictness.real = this->strictness;
      *(outbuffer + offset + 0) = (u_strictness.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strictness.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strictness.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strictness.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->strictness);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t start_controllers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      start_controllers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      start_controllers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      start_controllers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      start_controllers.resize(start_controllers_lengthT);
      for( uint32_t i = 0; i < start_controllers.size(); i++){
      uint32_t length_start_controllersi;
      arrToVar(length_start_controllersi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_start_controllersi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_start_controllersi-1]=0;
      this->start_controllers[i] = (char *)(inbuffer + offset-1);
      offset += length_start_controllersi;
      }
      uint32_t stop_controllers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_controllers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_controllers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_controllers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      stop_controllers.resize(stop_controllers_lengthT);
      for( uint32_t i = 0; i < stop_controllers.size(); i++){
      uint32_t length_stop_controllersi;
      arrToVar(length_stop_controllersi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_stop_controllersi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_stop_controllersi-1]=0;
      this->stop_controllers[i] = (char *)(inbuffer + offset-1);
      offset += length_stop_controllersi;
      }
      union {
        int32_t real;
        uint32_t base;
      } u_strictness;
      u_strictness.base = 0;
      u_strictness.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strictness.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strictness.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strictness.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->strictness = u_strictness.real;
      offset += sizeof(this->strictness);
     return offset;
    }

    const char * getType(){ return SWITCHCONTROLLER; };
    const char * getMD5(){ return "434da54adc434a5af5743ed711fd6ba1"; };

  };

  class SwitchControllerResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    SwitchControllerResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    const char * getType(){ return SWITCHCONTROLLER; };
    const char * getMD5(){ return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class SwitchController {
    public:
    typedef SwitchControllerRequest Request;
    typedef SwitchControllerResponse Response;
  };

}
#endif
