#ifndef _ROS_geometry_msgs_Polygon_h
#define _ROS_geometry_msgs_Polygon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace geometry_msgs
{

  class Polygon : public ros::Msg
  {
    public:
      std::vector<geometry_msgs::Point32> points;

    Polygon():
      points()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->points.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < points.size(); i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      points.resize(points_lengthT);
      for( uint32_t i = 0; i < points.size(); i++){
      offset += this->points[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "geometry_msgs/Polygon"; };
    const char * getMD5(){ return "cd60a26494a087f577976f0329fa120e"; };

  };

}
#endif