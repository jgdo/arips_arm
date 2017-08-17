#ifndef _ROS_std_msgs_UInt32MultiArray_h
#define _ROS_std_msgs_UInt32MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/MultiArrayLayout.h"

namespace std_msgs
{

  class UInt32MultiArray : public ros::Msg
  {
    public:
      typedef std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      std::vector<uint32_t> data;

    UInt32MultiArray():
      layout(),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->layout.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < data.size(); i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->layout.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      data.resize(data_lengthT);
      for( uint32_t i = 0; i < data.size(); i++){
      this->data[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->data[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    const char * getType(){ return "std_msgs/UInt32MultiArray"; };
    const char * getMD5(){ return "4d6a180abc9be191b96a7eda6c8a233d"; };

  };

}
#endif