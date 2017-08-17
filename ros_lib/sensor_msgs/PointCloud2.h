#ifndef _ROS_sensor_msgs_PointCloud2_h
#define _ROS_sensor_msgs_PointCloud2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointField.h"

namespace sensor_msgs
{

  class PointCloud2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _height_type;
      _height_type height;
      typedef uint32_t _width_type;
      _width_type width;
      std::vector<sensor_msgs::PointField> fields;
      typedef bool _is_bigendian_type;
      _is_bigendian_type is_bigendian;
      typedef uint32_t _point_step_type;
      _point_step_type point_step;
      typedef uint32_t _row_step_type;
      _row_step_type row_step;
      std::vector<uint8_t> data;
      typedef bool _is_dense_type;
      _is_dense_type is_dense;

    PointCloud2():
      header(),
      height(0),
      width(0),
      fields(),
      is_bigendian(0),
      point_step(0),
      row_step(0),
      data(),
      is_dense(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->fields.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fields.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fields.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fields.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fields.size(); i++){
      offset += this->fields[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_bigendian;
      u_is_bigendian.real = this->is_bigendian;
      *(outbuffer + offset + 0) = (u_is_bigendian.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_bigendian);
      *(outbuffer + offset + 0) = (this->point_step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_step);
      *(outbuffer + offset + 0) = (this->row_step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->row_step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->row_step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->row_step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->row_step);
      *(outbuffer + offset + 0) = (this->data.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < data.size(); i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_dense;
      u_is_dense.real = this->is_dense;
      *(outbuffer + offset + 0) = (u_is_dense.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_dense);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      uint32_t fields_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fields_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fields_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fields_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fields.resize(fields_lengthT);
      for( uint32_t i = 0; i < fields.size(); i++){
      offset += this->fields[i].deserialize(inbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_bigendian;
      u_is_bigendian.base = 0;
      u_is_bigendian.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_bigendian = u_is_bigendian.real;
      offset += sizeof(this->is_bigendian);
      this->point_step =  ((uint32_t) (*(inbuffer + offset)));
      this->point_step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->point_step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->point_step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->point_step);
      this->row_step =  ((uint32_t) (*(inbuffer + offset)));
      this->row_step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->row_step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->row_step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->row_step);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      data.resize(data_lengthT);
      for( uint32_t i = 0; i < data.size(); i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_dense;
      u_is_dense.base = 0;
      u_is_dense.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_dense = u_is_dense.real;
      offset += sizeof(this->is_dense);
     return offset;
    }

    const char * getType(){ return "sensor_msgs/PointCloud2"; };
    const char * getMD5(){ return "1158d486dd51d683ce2f1be655c3c181"; };

  };

}
#endif