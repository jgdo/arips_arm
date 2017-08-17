#ifndef _ROS_nav_msgs_Path_h
#define _ROS_nav_msgs_Path_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"

namespace nav_msgs
{

  class Path : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<geometry_msgs::PoseStamped> poses;

    Path():
      header(),
      poses()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->poses.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < poses.size(); i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      poses.resize(poses_lengthT);
      for( uint32_t i = 0; i < poses.size(); i++){
      offset += this->poses[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "nav_msgs/Path"; };
    const char * getMD5(){ return "6227e2b7e9cce15051f669a5e197bbf7"; };

  };

}
#endif