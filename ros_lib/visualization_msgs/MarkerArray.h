#ifndef _ROS_visualization_msgs_MarkerArray_h
#define _ROS_visualization_msgs_MarkerArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "visualization_msgs/Marker.h"

namespace visualization_msgs
{

  class MarkerArray : public ros::Msg
  {
    public:
      std::vector<visualization_msgs::Marker> markers;

    MarkerArray():
      markers()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->markers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < markers.size(); i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      markers.resize(markers_lengthT);
      for( uint32_t i = 0; i < markers.size(); i++){
      offset += this->markers[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/MarkerArray"; };
    const char * getMD5(){ return "90da67007c26525f655c1c269094e39f"; };

  };

}
#endif