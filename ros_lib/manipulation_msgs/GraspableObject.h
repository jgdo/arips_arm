#ifndef _ROS_manipulation_msgs_GraspableObject_h
#define _ROS_manipulation_msgs_GraspableObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "household_objects_database_msgs/DatabaseModelPose.h"
#include "sensor_msgs/PointCloud.h"
#include "manipulation_msgs/SceneRegion.h"

namespace manipulation_msgs
{

  class GraspableObject : public ros::Msg
  {
    public:
      typedef const char* _reference_frame_id_type;
      _reference_frame_id_type reference_frame_id;
      std::vector<household_objects_database_msgs::DatabaseModelPose> potential_models;
      typedef sensor_msgs::PointCloud _cluster_type;
      _cluster_type cluster;
      typedef manipulation_msgs::SceneRegion _region_type;
      _region_type region;
      typedef const char* _collision_name_type;
      _collision_name_type collision_name;

    GraspableObject():
      reference_frame_id(""),
      potential_models(),
      cluster(),
      region(),
      collision_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_reference_frame_id = strlen(this->reference_frame_id);
      varToArr(outbuffer + offset, length_reference_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->reference_frame_id, length_reference_frame_id);
      offset += length_reference_frame_id;
      *(outbuffer + offset + 0) = (this->potential_models.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->potential_models.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->potential_models.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->potential_models.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < potential_models.size(); i++){
      offset += this->potential_models[i].serialize(outbuffer + offset);
      }
      offset += this->cluster.serialize(outbuffer + offset);
      offset += this->region.serialize(outbuffer + offset);
      uint32_t length_collision_name = strlen(this->collision_name);
      varToArr(outbuffer + offset, length_collision_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision_name, length_collision_name);
      offset += length_collision_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_reference_frame_id;
      arrToVar(length_reference_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reference_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reference_frame_id-1]=0;
      this->reference_frame_id = (char *)(inbuffer + offset-1);
      offset += length_reference_frame_id;
      uint32_t potential_models_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      potential_models_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      potential_models_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      potential_models_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      potential_models.resize(potential_models_lengthT);
      for( uint32_t i = 0; i < potential_models.size(); i++){
      offset += this->potential_models[i].deserialize(inbuffer + offset);
      }
      offset += this->cluster.deserialize(inbuffer + offset);
      offset += this->region.deserialize(inbuffer + offset);
      uint32_t length_collision_name;
      arrToVar(length_collision_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision_name-1]=0;
      this->collision_name = (char *)(inbuffer + offset-1);
      offset += length_collision_name;
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspableObject"; };
    const char * getMD5(){ return "e2efd13d8e2bbb4697a5d71f167bceaa"; };

  };

}
#endif