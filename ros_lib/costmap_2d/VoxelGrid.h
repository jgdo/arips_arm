#ifndef _ROS_costmap_2d_VoxelGrid_h
#define _ROS_costmap_2d_VoxelGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"
#include "geometry_msgs/Vector3.h"

namespace costmap_2d
{

  class VoxelGrid : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<uint32_t> data;
      typedef geometry_msgs::Point32 _origin_type;
      _origin_type origin;
      typedef geometry_msgs::Vector3 _resolutions_type;
      _resolutions_type resolutions;
      typedef uint32_t _size_x_type;
      _size_x_type size_x;
      typedef uint32_t _size_y_type;
      _size_y_type size_y;
      typedef uint32_t _size_z_type;
      _size_z_type size_z;

    VoxelGrid():
      header(),
      data(),
      origin(),
      resolutions(),
      size_x(0),
      size_y(0),
      size_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->origin.serialize(outbuffer + offset);
      offset += this->resolutions.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->size_x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size_x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size_x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size_x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_x);
      *(outbuffer + offset + 0) = (this->size_y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size_y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size_y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size_y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_y);
      *(outbuffer + offset + 0) = (this->size_z >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size_z >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size_z >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size_z >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      offset += this->origin.deserialize(inbuffer + offset);
      offset += this->resolutions.deserialize(inbuffer + offset);
      this->size_x =  ((uint32_t) (*(inbuffer + offset)));
      this->size_x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size_x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size_x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size_x);
      this->size_y =  ((uint32_t) (*(inbuffer + offset)));
      this->size_y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size_y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size_y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size_y);
      this->size_z =  ((uint32_t) (*(inbuffer + offset)));
      this->size_z |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size_z |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size_z |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size_z);
     return offset;
    }

    const char * getType(){ return "costmap_2d/VoxelGrid"; };
    const char * getMD5(){ return "48a040827e1322073d78ece5a497029c"; };

  };

}
#endif