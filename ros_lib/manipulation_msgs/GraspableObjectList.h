#ifndef _ROS_manipulation_msgs_GraspableObjectList_h
#define _ROS_manipulation_msgs_GraspableObjectList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "manipulation_msgs/GraspableObject.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "shape_msgs/Mesh.h"
#include "geometry_msgs/Pose.h"

namespace manipulation_msgs
{

  class GraspableObjectList : public ros::Msg
  {
    public:
      std::vector<manipulation_msgs::GraspableObject> graspable_objects;
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::CameraInfo _camera_info_type;
      _camera_info_type camera_info;
      std::vector<shape_msgs::Mesh> meshes;
      typedef geometry_msgs::Pose _reference_to_camera_type;
      _reference_to_camera_type reference_to_camera;

    GraspableObjectList():
      graspable_objects(),
      image(),
      camera_info(),
      meshes(),
      reference_to_camera()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->graspable_objects.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->graspable_objects.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->graspable_objects.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->graspable_objects.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < graspable_objects.size(); i++){
      offset += this->graspable_objects[i].serialize(outbuffer + offset);
      }
      offset += this->image.serialize(outbuffer + offset);
      offset += this->camera_info.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->meshes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->meshes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->meshes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->meshes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < meshes.size(); i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
      }
      offset += this->reference_to_camera.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t graspable_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      graspable_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      graspable_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      graspable_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      graspable_objects.resize(graspable_objects_lengthT);
      for( uint32_t i = 0; i < graspable_objects.size(); i++){
      offset += this->graspable_objects[i].deserialize(inbuffer + offset);
      }
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->camera_info.deserialize(inbuffer + offset);
      uint32_t meshes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      meshes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      meshes.resize(meshes_lengthT);
      for( uint32_t i = 0; i < meshes.size(); i++){
      offset += this->meshes[i].deserialize(inbuffer + offset);
      }
      offset += this->reference_to_camera.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspableObjectList"; };
    const char * getMD5(){ return "d67571f2982f1b7115de1e0027319109"; };

  };

}
#endif