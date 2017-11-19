#ifndef _ROS_SERVICE_GraspPlanning_h
#define _ROS_SERVICE_GraspPlanning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/Grasp.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/CollisionObject.h"

namespace moveit_msgs
{

static const char GRASPPLANNING[] = "moveit_msgs/GraspPlanning";

  class GraspPlanningRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef moveit_msgs::CollisionObject _target_type;
      _target_type target;
      std::vector<char*> support_surfaces;
      std::vector<moveit_msgs::Grasp> candidate_grasps;
      std::vector<moveit_msgs::CollisionObject> movable_obstacles;

    GraspPlanningRequest():
      group_name(""),
      target(),
      support_surfaces(),
      candidate_grasps(),
      movable_obstacles()
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
      offset += this->target.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->support_surfaces.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->support_surfaces.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->support_surfaces.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->support_surfaces.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < support_surfaces.size(); i++){
      uint32_t length_support_surfacesi = strlen(this->support_surfaces[i]);
      varToArr(outbuffer + offset, length_support_surfacesi);
      offset += 4;
      memcpy(outbuffer + offset, this->support_surfaces[i], length_support_surfacesi);
      offset += length_support_surfacesi;
      }
      *(outbuffer + offset + 0) = (this->candidate_grasps.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->candidate_grasps.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->candidate_grasps.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->candidate_grasps.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < candidate_grasps.size(); i++){
      offset += this->candidate_grasps[i].serialize(outbuffer + offset);
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
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      offset += this->target.deserialize(inbuffer + offset);
      uint32_t support_surfaces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      support_surfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      support_surfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      support_surfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      support_surfaces.resize(support_surfaces_lengthT);
      for( uint32_t i = 0; i < support_surfaces.size(); i++){
      uint32_t length_support_surfacesi;
      arrToVar(length_support_surfacesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_support_surfacesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_support_surfacesi-1]=0;
      this->support_surfaces[i] = (char *)(inbuffer + offset-1);
      offset += length_support_surfacesi;
      }
      uint32_t candidate_grasps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      candidate_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      candidate_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      candidate_grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      candidate_grasps.resize(candidate_grasps_lengthT);
      for( uint32_t i = 0; i < candidate_grasps.size(); i++){
      offset += this->candidate_grasps[i].deserialize(inbuffer + offset);
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

    const char * getType(){ return GRASPPLANNING; };
    const char * getMD5(){ return "c234e9a645708cc86b57a43999746ae6"; };

  };

  class GraspPlanningResponse : public ros::Msg
  {
    public:
      std::vector<moveit_msgs::Grasp> grasps;
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    GraspPlanningResponse():
      grasps(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->grasps.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grasps.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grasps.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grasps.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < grasps.size(); i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t grasps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      grasps.resize(grasps_lengthT);
      for( uint32_t i = 0; i < grasps.size(); i++){
      offset += this->grasps[i].deserialize(inbuffer + offset);
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GRASPPLANNING; };
    const char * getMD5(){ return "bb8169d403b6e9f96bf61e22a50d13ae"; };

  };

  class GraspPlanning {
    public:
    typedef GraspPlanningRequest Request;
    typedef GraspPlanningResponse Response;
  };

}
#endif
