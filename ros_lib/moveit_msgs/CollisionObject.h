#ifndef _ROS_moveit_msgs_CollisionObject_h
#define _ROS_moveit_msgs_CollisionObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/ObjectType.h"
#include "shape_msgs/SolidPrimitive.h"
#include "geometry_msgs/Pose.h"
#include "shape_msgs/Mesh.h"
#include "shape_msgs/Plane.h"

namespace moveit_msgs
{

  class CollisionObject : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _id_type;
      _id_type id;
      typedef object_recognition_msgs::ObjectType _type_type;
      _type_type type;
      std::vector<shape_msgs::SolidPrimitive> primitives;
      std::vector<geometry_msgs::Pose> primitive_poses;
      std::vector<shape_msgs::Mesh> meshes;
      std::vector<geometry_msgs::Pose> mesh_poses;
      std::vector<shape_msgs::Plane> planes;
      std::vector<geometry_msgs::Pose> plane_poses;
      typedef int8_t _operation_type;
      _operation_type operation;
      enum { ADD = 0 };
      enum { REMOVE = 1 };
      enum { APPEND = 2 };
      enum { MOVE = 3 };

    CollisionObject():
      header(),
      id(""),
      type(),
      primitives(),
      primitive_poses(),
      meshes(),
      mesh_poses(),
      planes(),
      plane_poses(),
      operation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->type.serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->planes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < planes.size(); i++){
      offset += this->planes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->plane_poses.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_poses.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_poses.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_poses.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < plane_poses.size(); i++){
      offset += this->plane_poses[i].serialize(outbuffer + offset);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_operation;
      u_operation.real = this->operation;
      *(outbuffer + offset + 0) = (u_operation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->type.deserialize(inbuffer + offset);
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
      uint32_t planes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      planes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      planes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      planes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      planes.resize(planes_lengthT);
      for( uint32_t i = 0; i < planes.size(); i++){
      offset += this->planes[i].deserialize(inbuffer + offset);
      }
      uint32_t plane_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      plane_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      plane_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      plane_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      plane_poses.resize(plane_poses_lengthT);
      for( uint32_t i = 0; i < plane_poses.size(); i++){
      offset += this->plane_poses[i].deserialize(inbuffer + offset);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_operation;
      u_operation.base = 0;
      u_operation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation = u_operation.real;
      offset += sizeof(this->operation);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/CollisionObject"; };
    const char * getMD5(){ return "568a161b26dc46c54a5a07621ce82cf3"; };

  };

}
#endif