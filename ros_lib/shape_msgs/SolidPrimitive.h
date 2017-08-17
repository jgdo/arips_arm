#ifndef _ROS_shape_msgs_SolidPrimitive_h
#define _ROS_shape_msgs_SolidPrimitive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace shape_msgs
{

  class SolidPrimitive : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      std::vector<float> dimensions;
      enum { BOX = 1 };
      enum { SPHERE = 2 };
      enum { CYLINDER = 3 };
      enum { CONE = 4 };
      enum { BOX_X = 0 };
      enum { BOX_Y = 1 };
      enum { BOX_Z = 2 };
      enum { SPHERE_RADIUS = 0 };
      enum { CYLINDER_HEIGHT = 0 };
      enum { CYLINDER_RADIUS = 1 };
      enum { CONE_HEIGHT = 0 };
      enum { CONE_RADIUS = 1 };

    SolidPrimitive():
      type(0),
      dimensions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->dimensions.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dimensions.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dimensions.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dimensions.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < dimensions.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->dimensions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t dimensions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dimensions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dimensions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dimensions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      dimensions.resize(dimensions_lengthT);
      for( uint32_t i = 0; i < dimensions.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dimensions[i]));
      }
     return offset;
    }

    const char * getType(){ return "shape_msgs/SolidPrimitive"; };
    const char * getMD5(){ return "d8f8cbc74c5ff283fca29569ccefb45d"; };

  };

}
#endif