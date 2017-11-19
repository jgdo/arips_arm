#ifndef _ROS_manipulation_msgs_SceneRegion_h
#define _ROS_manipulation_msgs_SceneRegion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Vector3.h"

namespace manipulation_msgs
{

  class SceneRegion : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _cloud_type;
      _cloud_type cloud;
      std::vector<int32_t> mask;
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::Image _disparity_image_type;
      _disparity_image_type disparity_image;
      typedef sensor_msgs::CameraInfo _cam_info_type;
      _cam_info_type cam_info;
      typedef geometry_msgs::PoseStamped _roi_box_pose_type;
      _roi_box_pose_type roi_box_pose;
      typedef geometry_msgs::Vector3 _roi_box_dims_type;
      _roi_box_dims_type roi_box_dims;

    SceneRegion():
      cloud(),
      mask(),
      image(),
      disparity_image(),
      cam_info(),
      roi_box_pose(),
      roi_box_dims()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mask.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mask.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mask.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mask.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < mask.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_maski;
      u_maski.real = this->mask[i];
      *(outbuffer + offset + 0) = (u_maski.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maski.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maski.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maski.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mask[i]);
      }
      offset += this->image.serialize(outbuffer + offset);
      offset += this->disparity_image.serialize(outbuffer + offset);
      offset += this->cam_info.serialize(outbuffer + offset);
      offset += this->roi_box_pose.serialize(outbuffer + offset);
      offset += this->roi_box_dims.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
      uint32_t mask_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mask_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mask_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mask_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      mask.resize(mask_lengthT);
      for( uint32_t i = 0; i < mask.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_maski;
      u_maski.base = 0;
      u_maski.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maski.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maski.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maski.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mask[i] = u_maski.real;
      offset += sizeof(this->mask[i]);
      }
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->disparity_image.deserialize(inbuffer + offset);
      offset += this->cam_info.deserialize(inbuffer + offset);
      offset += this->roi_box_pose.deserialize(inbuffer + offset);
      offset += this->roi_box_dims.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/SceneRegion"; };
    const char * getMD5(){ return "0a9ab02b19292633619876c9d247690c"; };

  };

}
#endif