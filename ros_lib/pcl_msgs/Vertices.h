#ifndef _ROS_pcl_msgs_Vertices_h
#define _ROS_pcl_msgs_Vertices_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace pcl_msgs
{

  class Vertices : public ros::Msg
  {
    public:
      std::vector<uint32_t> vertices;

    Vertices():
      vertices()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->vertices.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < vertices.size(); i++){
      *(outbuffer + offset + 0) = (this->vertices[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t vertices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      vertices.resize(vertices_lengthT);
      for( uint32_t i = 0; i < vertices.size(); i++){
      this->vertices[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->vertices[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vertices[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->vertices[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->vertices[i]);
      }
     return offset;
    }

    const char * getType(){ return "pcl_msgs/Vertices"; };
    const char * getMD5(){ return "39bd7b1c23763ddd1b882b97cb7cfe11"; };

  };

}
#endif