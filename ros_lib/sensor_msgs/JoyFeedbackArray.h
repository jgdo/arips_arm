#ifndef _ROS_sensor_msgs_JoyFeedbackArray_h
#define _ROS_sensor_msgs_JoyFeedbackArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "sensor_msgs/JoyFeedback.h"

namespace sensor_msgs
{

  class JoyFeedbackArray : public ros::Msg
  {
    public:
      std::vector<sensor_msgs::JoyFeedback> array;

    JoyFeedbackArray():
      array()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->array.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->array.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->array.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->array.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < array.size(); i++){
      offset += this->array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t array_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      array.resize(array_lengthT);
      for( uint32_t i = 0; i < array.size(); i++){
      offset += this->array[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/JoyFeedbackArray"; };
    const char * getMD5(){ return "cde5730a895b1fc4dee6f91b754b213d"; };

  };

}
#endif