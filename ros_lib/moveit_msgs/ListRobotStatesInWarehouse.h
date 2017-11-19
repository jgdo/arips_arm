#ifndef _ROS_SERVICE_ListRobotStatesInWarehouse_h
#define _ROS_SERVICE_ListRobotStatesInWarehouse_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace moveit_msgs
{

static const char LISTROBOTSTATESINWAREHOUSE[] = "moveit_msgs/ListRobotStatesInWarehouse";

  class ListRobotStatesInWarehouseRequest : public ros::Msg
  {
    public:
      typedef const char* _regex_type;
      _regex_type regex;
      typedef const char* _robot_type;
      _robot_type robot;

    ListRobotStatesInWarehouseRequest():
      regex(""),
      robot("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_regex = strlen(this->regex);
      varToArr(outbuffer + offset, length_regex);
      offset += 4;
      memcpy(outbuffer + offset, this->regex, length_regex);
      offset += length_regex;
      uint32_t length_robot = strlen(this->robot);
      varToArr(outbuffer + offset, length_robot);
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_robot);
      offset += length_robot;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_regex;
      arrToVar(length_regex, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_regex; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_regex-1]=0;
      this->regex = (char *)(inbuffer + offset-1);
      offset += length_regex;
      uint32_t length_robot;
      arrToVar(length_robot, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_robot;
     return offset;
    }

    const char * getType(){ return LISTROBOTSTATESINWAREHOUSE; };
    const char * getMD5(){ return "6f0970a3ca837e2fc3ed63e314b44b42"; };

  };

  class ListRobotStatesInWarehouseResponse : public ros::Msg
  {
    public:
      std::vector<char*> states;

    ListRobotStatesInWarehouseResponse():
      states()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->states.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < states.size(); i++){
      uint32_t length_statesi = strlen(this->states[i]);
      varToArr(outbuffer + offset, length_statesi);
      offset += 4;
      memcpy(outbuffer + offset, this->states[i], length_statesi);
      offset += length_statesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      states.resize(states_lengthT);
      for( uint32_t i = 0; i < states.size(); i++){
      uint32_t length_statesi;
      arrToVar(length_statesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_statesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_statesi-1]=0;
      this->states[i] = (char *)(inbuffer + offset-1);
      offset += length_statesi;
      }
     return offset;
    }

    const char * getType(){ return LISTROBOTSTATESINWAREHOUSE; };
    const char * getMD5(){ return "a8656b247c0429bb79afe0ddb88eb2f5"; };

  };

  class ListRobotStatesInWarehouse {
    public:
    typedef ListRobotStatesInWarehouseRequest Request;
    typedef ListRobotStatesInWarehouseResponse Response;
  };

}
#endif
