#ifndef _ROS_moveit_msgs_BoundingVolume_h
#define _ROS_moveit_msgs_BoundingVolume_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "shape_msgs/SolidPrimitive.h"
#include "geometry_msgs/Pose.h"
#include "shape_msgs/Mesh.h"

namespace moveit_msgs
{

  class BoundingVolume : public ros::Msg
  {
    public:
      std::vector<shape_msgs::SolidPrimitive> primitives;
      std::vector<geometry_msgs::Pose> primitive_poses;
      std::vector<shape_msgs::Mesh> meshes;
      std::vector<geometry_msgs::Pose> mesh_poses;

    BoundingVolume():
      primitives(),
      primitive_poses(),
      meshes(),
      mesh_poses()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->primitives.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->primitives.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->primitives.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->primitives.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < primitives.size(); i++){
      offset += this->primitives[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->primitive_poses.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->primitive_poses.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->primitive_poses.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->primitive_poses.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < primitive_poses.size(); i++){
      offset += this->primitive_poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->meshes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->meshes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->meshes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->meshes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < meshes.size(); i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->mesh_poses.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mesh_poses.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mesh_poses.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mesh_poses.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < mesh_poses.size(); i++){
      offset += this->mesh_poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t primitives_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      primitives_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      primitives_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      primitives_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      primitives.resize(primitives_lengthT);
      for( uint32_t i = 0; i < primitives.size(); i++){
      offset += this->primitives[i].deserialize(inbuffer + offset);
      }
      uint32_t primitive_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      primitive_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      primitive_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      primitive_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      primitive_poses.resize(primitive_poses_lengthT);
      for( uint32_t i = 0; i < primitive_poses.size(); i++){
      offset += this->primitive_poses[i].deserialize(inbuffer + offset);
      }
      uint32_t meshes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      meshes.resize(meshes_lengthT);
      for( uint32_t i = 0; i < meshes.size(); i++){
      offset += this->meshes[i].deserialize(inbuffer + offset);
      }
      uint32_t mesh_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mesh_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mesh_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mesh_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      mesh_poses.resize(mesh_poses_lengthT);
      for( uint32_t i = 0; i < mesh_poses.size(); i++){
      offset += this->mesh_poses[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/BoundingVolume"; };
    const char * getMD5(){ return "22db94010f39e9198032cb4a1aeda26e"; };

  };

}
#endif