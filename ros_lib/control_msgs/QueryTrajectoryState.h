#ifndef _ROS_SERVICE_QueryTrajectoryState_h
#define _ROS_SERVICE_QueryTrajectoryState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "ros/time.h"

namespace control_msgs
{

static const char QUERYTRAJECTORYSTATE[] = "control_msgs/QueryTrajectoryState";

  class QueryTrajectoryStateRequest : public ros::Msg
  {
    public:
      typedef ros::Time _time_type;
      _time_type time;

    QueryTrajectoryStateRequest():
      time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.sec);
      *(outbuffer + offset + 0) = (this->time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.sec);
      this->time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.nsec);
     return offset;
    }

    const char * getType(){ return QUERYTRAJECTORYSTATE; };
    const char * getMD5(){ return "556a4fb76023a469987922359d08a844"; };

  };

  class QueryTrajectoryStateResponse : public ros::Msg
  {
    public:
      std::vector<char*> name;
      std::vector<float> position;
      std::vector<float> velocity;
      std::vector<float> acceleration;

    QueryTrajectoryStateResponse():
      name(),
      position(),
      velocity(),
      acceleration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->name.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < name.size(); i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->position.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < position.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->position[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < velocity.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->acceleration.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->acceleration.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->acceleration.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->acceleration.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < acceleration.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      name.resize(name_lengthT);
      for( uint32_t i = 0; i < name.size(); i++){
      uint32_t length_namei;
      arrToVar(length_namei, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namei; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namei-1]=0;
      this->name[i] = (char *)(inbuffer + offset-1);
      offset += length_namei;
      }
      uint32_t position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      position.resize(position_lengthT);
      for( uint32_t i = 0; i < position.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position[i]));
      }
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      velocity.resize(velocity_lengthT);
      for( uint32_t i = 0; i < velocity.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity[i]));
      }
      uint32_t acceleration_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      acceleration_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      acceleration_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      acceleration_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      acceleration.resize(acceleration_lengthT);
      for( uint32_t i = 0; i < acceleration.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration[i]));
      }
     return offset;
    }

    const char * getType(){ return QUERYTRAJECTORYSTATE; };
    const char * getMD5(){ return "1f1a6554ad060f44d013e71868403c1a"; };

  };

  class QueryTrajectoryState {
    public:
    typedef QueryTrajectoryStateRequest Request;
    typedef QueryTrajectoryStateResponse Response;
  };

}
#endif
