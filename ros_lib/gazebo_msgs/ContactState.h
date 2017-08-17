#ifndef _ROS_gazebo_msgs_ContactState_h
#define _ROS_gazebo_msgs_ContactState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "geometry_msgs/Wrench.h"
#include "geometry_msgs/Vector3.h"

namespace gazebo_msgs
{

  class ContactState : public ros::Msg
  {
    public:
      typedef const char* _info_type;
      _info_type info;
      typedef const char* _collision1_name_type;
      _collision1_name_type collision1_name;
      typedef const char* _collision2_name_type;
      _collision2_name_type collision2_name;
      std::vector<geometry_msgs::Wrench> wrenches;
      typedef geometry_msgs::Wrench _total_wrench_type;
      _total_wrench_type total_wrench;
      std::vector<geometry_msgs::Vector3> contact_positions;
      std::vector<geometry_msgs::Vector3> contact_normals;
      std::vector<float> depths;

    ContactState():
      info(""),
      collision1_name(""),
      collision2_name(""),
      wrenches(),
      total_wrench(),
      contact_positions(),
      contact_normals(),
      depths()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_info = strlen(this->info);
      varToArr(outbuffer + offset, length_info);
      offset += 4;
      memcpy(outbuffer + offset, this->info, length_info);
      offset += length_info;
      uint32_t length_collision1_name = strlen(this->collision1_name);
      varToArr(outbuffer + offset, length_collision1_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision1_name, length_collision1_name);
      offset += length_collision1_name;
      uint32_t length_collision2_name = strlen(this->collision2_name);
      varToArr(outbuffer + offset, length_collision2_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision2_name, length_collision2_name);
      offset += length_collision2_name;
      *(outbuffer + offset + 0) = (this->wrenches.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wrenches.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wrenches.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wrenches.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < wrenches.size(); i++){
      offset += this->wrenches[i].serialize(outbuffer + offset);
      }
      offset += this->total_wrench.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contact_positions.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contact_positions.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contact_positions.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contact_positions.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < contact_positions.size(); i++){
      offset += this->contact_positions[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->contact_normals.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contact_normals.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contact_normals.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contact_normals.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < contact_normals.size(); i++){
      offset += this->contact_normals[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->depths.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->depths.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->depths.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->depths.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < depths.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->depths[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_info;
      arrToVar(length_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info-1]=0;
      this->info = (char *)(inbuffer + offset-1);
      offset += length_info;
      uint32_t length_collision1_name;
      arrToVar(length_collision1_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision1_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision1_name-1]=0;
      this->collision1_name = (char *)(inbuffer + offset-1);
      offset += length_collision1_name;
      uint32_t length_collision2_name;
      arrToVar(length_collision2_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision2_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision2_name-1]=0;
      this->collision2_name = (char *)(inbuffer + offset-1);
      offset += length_collision2_name;
      uint32_t wrenches_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      wrenches.resize(wrenches_lengthT);
      for( uint32_t i = 0; i < wrenches.size(); i++){
      offset += this->wrenches[i].deserialize(inbuffer + offset);
      }
      offset += this->total_wrench.deserialize(inbuffer + offset);
      uint32_t contact_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contact_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      contact_positions.resize(contact_positions_lengthT);
      for( uint32_t i = 0; i < contact_positions.size(); i++){
      offset += this->contact_positions[i].deserialize(inbuffer + offset);
      }
      uint32_t contact_normals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contact_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      contact_normals.resize(contact_normals_lengthT);
      for( uint32_t i = 0; i < contact_normals.size(); i++){
      offset += this->contact_normals[i].deserialize(inbuffer + offset);
      }
      uint32_t depths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      depths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      depths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      depths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      depths.resize(depths_lengthT);
      for( uint32_t i = 0; i < depths.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->depths[i]));
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ContactState"; };
    const char * getMD5(){ return "48c0ffb054b8c444f870cecea1ee50d9"; };

  };

}
#endif