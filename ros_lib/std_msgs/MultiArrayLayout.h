#ifndef _ROS_std_msgs_MultiArrayLayout_h
#define _ROS_std_msgs_MultiArrayLayout_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/MultiArrayDimension.h"

namespace std_msgs
{

  class MultiArrayLayout : public ros::Msg
  {
    public:
      std::vector<std_msgs::MultiArrayDimension> dim;
      typedef uint32_t _data_offset_type;
      _data_offset_type data_offset;

    MultiArrayLayout():
      dim(),
      data_offset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->dim.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dim.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dim.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dim.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < dim.size(); i++){
      offset += this->dim[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->data_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t dim_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dim_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dim_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dim_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      dim.resize(dim_lengthT);
      for( uint32_t i = 0; i < dim.size(); i++){
      offset += this->dim[i].deserialize(inbuffer + offset);
      }
      this->data_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data_offset);
     return offset;
    }

    const char * getType(){ return "std_msgs/MultiArrayLayout"; };
    const char * getMD5(){ return "0fed2a11c13e11c5571b4e2a995a91a3"; };

  };

}
#endif