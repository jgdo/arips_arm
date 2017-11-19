#ifndef _ROS_object_recognition_msgs_Table_h
#define _ROS_object_recognition_msgs_Table_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace object_recognition_msgs
{

  class Table : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      std::vector<geometry_msgs::Point> convex_hull;

    Table():
      header(),
      pose(),
      convex_hull()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->convex_hull.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->convex_hull.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->convex_hull.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->convex_hull.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < convex_hull.size(); i++){
      offset += this->convex_hull[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t convex_hull_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      convex_hull_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      convex_hull_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      convex_hull_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      convex_hull.resize(convex_hull_lengthT);
      for( uint32_t i = 0; i < convex_hull.size(); i++){
      offset += this->convex_hull[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/Table"; };
    const char * getMD5(){ return "39efebc7d51e44bd2d72f2df6c7823a2"; };

  };

}
#endif