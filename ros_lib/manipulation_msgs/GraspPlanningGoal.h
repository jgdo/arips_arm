#ifndef _ROS_manipulation_msgs_GraspPlanningGoal_h
#define _ROS_manipulation_msgs_GraspPlanningGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "manipulation_msgs/GraspableObject.h"
#include "manipulation_msgs/Grasp.h"

namespace manipulation_msgs
{

  class GraspPlanningGoal : public ros::Msg
  {
    public:
      typedef const char* _arm_name_type;
      _arm_name_type arm_name;
      typedef manipulation_msgs::GraspableObject _target_type;
      _target_type target;
      typedef const char* _collision_object_name_type;
      _collision_object_name_type collision_object_name;
      typedef const char* _collision_support_surface_name_type;
      _collision_support_surface_name_type collision_support_surface_name;
      std::vector<manipulation_msgs::Grasp> grasps_to_evaluate;
      std::vector<manipulation_msgs::GraspableObject> movable_obstacles;

    GraspPlanningGoal():
      arm_name(""),
      target(),
      collision_object_name(""),
      collision_support_surface_name(""),
      grasps_to_evaluate(),
      movable_obstacles()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_arm_name = strlen(this->arm_name);
      varToArr(outbuffer + offset, length_arm_name);
      offset += 4;
      memcpy(outbuffer + offset, this->arm_name, length_arm_name);
      offset += length_arm_name;
      offset += this->target.serialize(outbuffer + offset);
      uint32_t length_collision_object_name = strlen(this->collision_object_name);
      varToArr(outbuffer + offset, length_collision_object_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision_object_name, length_collision_object_name);
      offset += length_collision_object_name;
      uint32_t length_collision_support_surface_name = strlen(this->collision_support_surface_name);
      varToArr(outbuffer + offset, length_collision_support_surface_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision_support_surface_name, length_collision_support_surface_name);
      offset += length_collision_support_surface_name;
      *(outbuffer + offset + 0) = (this->grasps_to_evaluate.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grasps_to_evaluate.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grasps_to_evaluate.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grasps_to_evaluate.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < grasps_to_evaluate.size(); i++){
      offset += this->grasps_to_evaluate[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->movable_obstacles.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->movable_obstacles.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->movable_obstacles.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->movable_obstacles.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < movable_obstacles.size(); i++){
      offset += this->movable_obstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_arm_name;
      arrToVar(length_arm_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arm_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arm_name-1]=0;
      this->arm_name = (char *)(inbuffer + offset-1);
      offset += length_arm_name;
      offset += this->target.deserialize(inbuffer + offset);
      uint32_t length_collision_object_name;
      arrToVar(length_collision_object_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision_object_name-1]=0;
      this->collision_object_name = (char *)(inbuffer + offset-1);
      offset += length_collision_object_name;
      uint32_t length_collision_support_surface_name;
      arrToVar(length_collision_support_surface_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision_support_surface_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision_support_surface_name-1]=0;
      this->collision_support_surface_name = (char *)(inbuffer + offset-1);
      offset += length_collision_support_surface_name;
      uint32_t grasps_to_evaluate_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grasps_to_evaluate_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grasps_to_evaluate_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grasps_to_evaluate_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      grasps_to_evaluate.resize(grasps_to_evaluate_lengthT);
      for( uint32_t i = 0; i < grasps_to_evaluate.size(); i++){
      offset += this->grasps_to_evaluate[i].deserialize(inbuffer + offset);
      }
      uint32_t movable_obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      movable_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      movable_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      movable_obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      movable_obstacles.resize(movable_obstacles_lengthT);
      for( uint32_t i = 0; i < movable_obstacles.size(); i++){
      offset += this->movable_obstacles[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspPlanningGoal"; };
    const char * getMD5(){ return "077dca08a07415d82d6ab047890161f4"; };

  };

}
#endif