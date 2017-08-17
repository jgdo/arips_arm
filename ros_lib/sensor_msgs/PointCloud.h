#ifndef _ROS_sensor_msgs_PointCloud_h
#define _ROS_sensor_msgs_PointCloud_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"
#include "sensor_msgs/ChannelFloat32.h"

namespace sensor_msgs
{

  class PointCloud : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<geometry_msgs::Point32> points;
      std::vector<sensor_msgs::ChannelFloat32> channels;

    PointCloud():
      header(),
      points(),
      channels()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->points.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < points.size(); i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->channels.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channels.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channels.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channels.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < channels.size(); i++){
      offset += this->channels[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      points.resize(points_lengthT);
      for( uint32_t i = 0; i < points.size(); i++){
      offset += this->points[i].deserialize(inbuffer + offset);
      }
      uint32_t channels_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channels_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      channels.resize(channels_lengthT);
      for( uint32_t i = 0; i < channels.size(); i++){
      offset += this->channels[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/PointCloud"; };
    const char * getMD5(){ return "d8e9c3f5afbdd8a130fd1d2763945fca"; };

  };

}
#endif