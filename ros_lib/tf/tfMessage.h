#ifndef _ROS_tf_tfMessage_h
#define _ROS_tf_tfMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"

namespace tf
{

  class tfMessage : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::TransformStamped> transforms;

    tfMessage():
      transforms()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->transforms.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < transforms.size(); i++){
      offset += this->transforms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      transforms.resize(transforms_lengthT);
      for( uint32_t i = 0; i < transforms.size(); i++){
      offset += this->transforms[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "tf/tfMessage"; };
    const char * getMD5(){ return "94810edda583a504dfda3829e70d7eec"; };

  };

}
#endif