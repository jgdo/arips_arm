#ifndef _ROS_moveit_msgs_PlanningScene_h
#define _ROS_moveit_msgs_PlanningScene_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "geometry_msgs/TransformStamped.h"
#include "moveit_msgs/AllowedCollisionMatrix.h"
#include "moveit_msgs/LinkPadding.h"
#include "moveit_msgs/LinkScale.h"
#include "moveit_msgs/ObjectColor.h"
#include "moveit_msgs/PlanningSceneWorld.h"

namespace moveit_msgs
{

  class PlanningScene : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef moveit_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      typedef const char* _robot_model_name_type;
      _robot_model_name_type robot_model_name;
      std::vector<geometry_msgs::TransformStamped> fixed_frame_transforms;
      typedef moveit_msgs::AllowedCollisionMatrix _allowed_collision_matrix_type;
      _allowed_collision_matrix_type allowed_collision_matrix;
      std::vector<moveit_msgs::LinkPadding> link_padding;
      std::vector<moveit_msgs::LinkScale> link_scale;
      std::vector<moveit_msgs::ObjectColor> object_colors;
      typedef moveit_msgs::PlanningSceneWorld _world_type;
      _world_type world;
      typedef bool _is_diff_type;
      _is_diff_type is_diff;

    PlanningScene():
      name(""),
      robot_state(),
      robot_model_name(""),
      fixed_frame_transforms(),
      allowed_collision_matrix(),
      link_padding(),
      link_scale(),
      object_colors(),
      world(),
      is_diff(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->robot_state.serialize(outbuffer + offset);
      uint32_t length_robot_model_name = strlen(this->robot_model_name);
      varToArr(outbuffer + offset, length_robot_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_model_name, length_robot_model_name);
      offset += length_robot_model_name;
      *(outbuffer + offset + 0) = (this->fixed_frame_transforms.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fixed_frame_transforms.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fixed_frame_transforms.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fixed_frame_transforms.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fixed_frame_transforms.size(); i++){
      offset += this->fixed_frame_transforms[i].serialize(outbuffer + offset);
      }
      offset += this->allowed_collision_matrix.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->link_padding.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_padding.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_padding.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_padding.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < link_padding.size(); i++){
      offset += this->link_padding[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->link_scale.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_scale.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_scale.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_scale.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < link_scale.size(); i++){
      offset += this->link_scale[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->object_colors.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->object_colors.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->object_colors.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->object_colors.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < object_colors.size(); i++){
      offset += this->object_colors[i].serialize(outbuffer + offset);
      }
      offset += this->world.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_diff;
      u_is_diff.real = this->is_diff;
      *(outbuffer + offset + 0) = (u_is_diff.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_diff);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->robot_state.deserialize(inbuffer + offset);
      uint32_t length_robot_model_name;
      arrToVar(length_robot_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_model_name-1]=0;
      this->robot_model_name = (char *)(inbuffer + offset-1);
      offset += length_robot_model_name;
      uint32_t fixed_frame_transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fixed_frame_transforms.resize(fixed_frame_transforms_lengthT);
      for( uint32_t i = 0; i < fixed_frame_transforms.size(); i++){
      offset += this->fixed_frame_transforms[i].deserialize(inbuffer + offset);
      }
      offset += this->allowed_collision_matrix.deserialize(inbuffer + offset);
      uint32_t link_padding_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      link_padding.resize(link_padding_lengthT);
      for( uint32_t i = 0; i < link_padding.size(); i++){
      offset += this->link_padding[i].deserialize(inbuffer + offset);
      }
      uint32_t link_scale_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_scale_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      link_scale.resize(link_scale_lengthT);
      for( uint32_t i = 0; i < link_scale.size(); i++){
      offset += this->link_scale[i].deserialize(inbuffer + offset);
      }
      uint32_t object_colors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      object_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      object_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      object_colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      object_colors.resize(object_colors_lengthT);
      for( uint32_t i = 0; i < object_colors.size(); i++){
      offset += this->object_colors[i].deserialize(inbuffer + offset);
      }
      offset += this->world.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_diff;
      u_is_diff.base = 0;
      u_is_diff.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_diff = u_is_diff.real;
      offset += sizeof(this->is_diff);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlanningScene"; };
    const char * getMD5(){ return "89aac6d20db967ba716cba5a86b1b9d5"; };

  };

}
#endif