#ifndef _ROS_moveit_msgs_PlaceGoal_h
#define _ROS_moveit_msgs_PlaceGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/PlaceLocation.h"
#include "moveit_msgs/Constraints.h"
#include "moveit_msgs/PlanningOptions.h"

namespace moveit_msgs
{

  class PlaceGoal : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef const char* _attached_object_name_type;
      _attached_object_name_type attached_object_name;
      std::vector<moveit_msgs::PlaceLocation> place_locations;
      typedef bool _place_eef_type;
      _place_eef_type place_eef;
      typedef const char* _support_surface_name_type;
      _support_surface_name_type support_surface_name;
      typedef bool _allow_gripper_support_collision_type;
      _allow_gripper_support_collision_type allow_gripper_support_collision;
      typedef moveit_msgs::Constraints _path_constraints_type;
      _path_constraints_type path_constraints;
      typedef const char* _planner_id_type;
      _planner_id_type planner_id;
      std::vector<char*> allowed_touch_objects;
      typedef float _allowed_planning_time_type;
      _allowed_planning_time_type allowed_planning_time;
      typedef moveit_msgs::PlanningOptions _planning_options_type;
      _planning_options_type planning_options;

    PlaceGoal():
      group_name(""),
      attached_object_name(""),
      place_locations(),
      place_eef(0),
      support_surface_name(""),
      allow_gripper_support_collision(0),
      path_constraints(),
      planner_id(""),
      allowed_touch_objects(),
      allowed_planning_time(0),
      planning_options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      uint32_t length_attached_object_name = strlen(this->attached_object_name);
      varToArr(outbuffer + offset, length_attached_object_name);
      offset += 4;
      memcpy(outbuffer + offset, this->attached_object_name, length_attached_object_name);
      offset += length_attached_object_name;
      *(outbuffer + offset + 0) = (this->place_locations.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->place_locations.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->place_locations.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->place_locations.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < place_locations.size(); i++){
      offset += this->place_locations[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_place_eef;
      u_place_eef.real = this->place_eef;
      *(outbuffer + offset + 0) = (u_place_eef.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->place_eef);
      uint32_t length_support_surface_name = strlen(this->support_surface_name);
      varToArr(outbuffer + offset, length_support_surface_name);
      offset += 4;
      memcpy(outbuffer + offset, this->support_surface_name, length_support_surface_name);
      offset += length_support_surface_name;
      union {
        bool real;
        uint8_t base;
      } u_allow_gripper_support_collision;
      u_allow_gripper_support_collision.real = this->allow_gripper_support_collision;
      *(outbuffer + offset + 0) = (u_allow_gripper_support_collision.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_gripper_support_collision);
      offset += this->path_constraints.serialize(outbuffer + offset);
      uint32_t length_planner_id = strlen(this->planner_id);
      varToArr(outbuffer + offset, length_planner_id);
      offset += 4;
      memcpy(outbuffer + offset, this->planner_id, length_planner_id);
      offset += length_planner_id;
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
      offset += serializeAvrFloat64(outbuffer + offset, this->allowed_planning_time);
      offset += this->planning_options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      uint32_t length_attached_object_name;
      arrToVar(length_attached_object_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_attached_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_attached_object_name-1]=0;
      this->attached_object_name = (char *)(inbuffer + offset-1);
      offset += length_attached_object_name;
      uint32_t place_locations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      place_locations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      place_locations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      place_locations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      place_locations.resize(place_locations_lengthT);
      for( uint32_t i = 0; i < place_locations.size(); i++){
      offset += this->place_locations[i].deserialize(inbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_place_eef;
      u_place_eef.base = 0;
      u_place_eef.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->place_eef = u_place_eef.real;
      offset += sizeof(this->place_eef);
      uint32_t length_support_surface_name;
      arrToVar(length_support_surface_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_support_surface_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_support_surface_name-1]=0;
      this->support_surface_name = (char *)(inbuffer + offset-1);
      offset += length_support_surface_name;
      union {
        bool real;
        uint8_t base;
      } u_allow_gripper_support_collision;
      u_allow_gripper_support_collision.base = 0;
      u_allow_gripper_support_collision.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_gripper_support_collision = u_allow_gripper_support_collision.real;
      offset += sizeof(this->allow_gripper_support_collision);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      uint32_t length_planner_id;
      arrToVar(length_planner_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_id-1]=0;
      this->planner_id = (char *)(inbuffer + offset-1);
      offset += length_planner_id;
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->allowed_planning_time));
      offset += this->planning_options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlaceGoal"; };
    const char * getMD5(){ return "e3f3e956e536ccd313fd8f23023f0a94"; };

  };

}
#endif