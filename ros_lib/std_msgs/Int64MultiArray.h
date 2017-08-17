#ifndef _ROS_std_msgs_Int64MultiArray_h
#define _ROS_std_msgs_Int64MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/MultiArrayLayout.h"

namespace std_msgs
{

  class Int64MultiArray : public ros::Msg
  {
    public:
      typedef std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      std::vector<int64_t> data;

    Int64MultiArray():
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
      union {
        int64_t real;
        uint64_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_datai.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_datai.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_datai.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_datai.base >> (8 * 7)) & 0xFF;
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
      union {
        int64_t real;
        uint64_t base;
      } u_datai;
      u_datai.base = 0;
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_datai.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->data[i] = u_datai.real;
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    const char * getType(){ return "std_msgs/Int64MultiArray"; };
    const char * getMD5(){ return "54865aa6c65be0448113a2afc6a49270"; };

  };

}
#endif