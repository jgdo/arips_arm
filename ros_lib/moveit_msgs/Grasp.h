#ifndef _ROS_moveit_msgs_Grasp_h
#define _ROS_moveit_msgs_Grasp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "geometry_msgs/PoseStamped.h"
#include "moveit_msgs/GripperTranslation.h"

namespace moveit_msgs
{

  class Grasp : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef trajectory_msgs::JointTrajectory _pre_grasp_posture_type;
      _pre_grasp_posture_type pre_grasp_posture;
      typedef trajectory_msgs::JointTrajectory _grasp_posture_type;
      _grasp_posture_type grasp_posture;
      typedef geometry_msgs::PoseStamped _grasp_pose_type;
      _grasp_pose_type grasp_pose;
      typedef float _grasp_quality_type;
      _grasp_quality_type grasp_quality;
      typedef moveit_msgs::GripperTranslation _pre_grasp_approach_type;
      _pre_grasp_approach_type pre_grasp_approach;
      typedef moveit_msgs::GripperTranslation _post_grasp_retreat_type;
      _post_grasp_retreat_type post_grasp_retreat;
      typedef moveit_msgs::GripperTranslation _post_place_retreat_type;
      _post_place_retreat_type post_place_retreat;
      typedef float _max_contact_force_type;
      _max_contact_force_type max_contact_force;
      std::vector<char*> allowed_touch_objects;

    Grasp():
      id(""),
      pre_grasp_posture(),
      grasp_posture(),
      grasp_pose(),
      grasp_quality(0),
      pre_grasp_approach(),
      post_grasp_retreat(),
      post_place_retreat(),
      max_contact_force(0),
      allowed_touch_objects()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->pre_grasp_posture.serialize(outbuffer + offset);
      offset += this->grasp_posture.serialize(outbuffer + offset);
      offset += this->grasp_pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->grasp_quality);
      offset += this->pre_grasp_approach.serialize(outbuffer + offset);
      offset += this->post_grasp_retreat.serialize(outbuffer + offset);
      offset += this->post_place_retreat.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_max_contact_force;
      u_max_contact_force.real = this->max_contact_force;
      *(outbuffer + offset + 0) = (u_max_contact_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_contact_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_contact_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_contact_force.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_contact_force);
      *(outbuffer + offset + 0) = (this->allowed_touch_objects.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_touch_objects.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_touch_objects.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_touch_objects.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < allowed_touch_objects.size(); i++){
      uint32_t length_allowed_touch_objectsi = strlen(this->allowed_touch_objects[i]);
      varToArr(outbuffer + offset, length_allowed_touch_objectsi);
      offset += 4;
      memcpy(outbuffer + offset, this->allowed_touch_objects[i], length_allowed_touch_objectsi);
      offset += length_allowed_touch_objectsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->pre_grasp_posture.deserialize(inbuffer + offset);
      offset += this->grasp_posture.deserialize(inbuffer + offset);
      offset += this->grasp_pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->grasp_quality));
      offset += this->pre_grasp_approach.deserialize(inbuffer + offset);
      offset += this->post_grasp_retreat.deserialize(inbuffer + offset);
      offset += this->post_place_retreat.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_max_contact_force;
      u_max_contact_force.base = 0;
      u_max_contact_force.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_contact_force.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_contact_force.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_contact_force.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_contact_force = u_max_contact_force.real;
      offset += sizeof(this->max_contact_force);
      uint32_t allowed_touch_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      allowed_touch_objects.resize(allowed_touch_objects_lengthT);
      for( uint32_t i = 0; i < allowed_touch_objects.size(); i++){
      uint32_t length_allowed_touch_objectsi;
      arrToVar(length_allowed_touch_objectsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_allowed_touch_objectsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_allowed_touch_objectsi-1]=0;
      this->allowed_touch_objects[i] = (char *)(inbuffer + offset-1);
      offset += length_allowed_touch_objectsi;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/Grasp"; };
    const char * getMD5(){ return "e26c8fb64f589c33c5d5e54bd7b5e4cb"; };

  };

}
#endif