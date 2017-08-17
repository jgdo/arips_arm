#ifndef _ROS_shape_msgs_Mesh_h
#define _ROS_shape_msgs_Mesh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "shape_msgs/MeshTriangle.h"
#include "geometry_msgs/Point.h"

namespace shape_msgs
{

  class Mesh : public ros::Msg
  {
    public:
      std::vector<shape_msgs::MeshTriangle> triangles;
      std::vector<geometry_msgs::Point> vertices;

    Mesh():
      triangles(),
      vertices()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->triangles.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->triangles.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->triangles.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->triangles.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < triangles.size(); i++){
      offset += this->triangles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->vertices.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < vertices.size(); i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t triangles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      triangles.resize(triangles_lengthT);
      for( uint32_t i = 0; i < triangles.size(); i++){
      offset += this->triangles[i].deserialize(inbuffer + offset);
      }
      uint32_t vertices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      vertices.resize(vertices_lengthT);
      for( uint32_t i = 0; i < vertices.size(); i++){
      offset += this->vertices[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "shape_msgs/Mesh"; };
    const char * getMD5(){ return "1ffdae9486cd3316a121c578b47a85cc"; };

  };

}
#endif