#ifndef _ROS_visualization_msgs_InteractiveMarker_h
#define _ROS_visualization_msgs_InteractiveMarker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "visualization_msgs/MenuEntry.h"
#include "visualization_msgs/InteractiveMarkerControl.h"

namespace visualization_msgs
{

  class InteractiveMarker : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _description_type;
      _description_type description;
      typedef float _scale_type;
      _scale_type scale;
      std::vector<visualization_msgs::MenuEntry> menu_entries;
      std::vector<visualization_msgs::InteractiveMarkerControl> controls;

    InteractiveMarker():
      header(),
      pose(),
      name(""),
      description(""),
      scale(0),
      menu_entries(),
      controls()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.real = this->scale;
      *(outbuffer + offset + 0) = (u_scale.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scale.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scale.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scale.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scale);
      *(outbuffer + offset + 0) = (this->menu_entries.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->menu_entries.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->menu_entries.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->menu_entries.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < menu_entries.size(); i++){
      offset += this->menu_entries[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->controls.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->controls.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->controls.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->controls.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < controls.size(); i++){
      offset += this->controls[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.base = 0;
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scale = u_scale.real;
      offset += sizeof(this->scale);
      uint32_t menu_entries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      menu_entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      menu_entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      menu_entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      menu_entries.resize(menu_entries_lengthT);
      for( uint32_t i = 0; i < menu_entries.size(); i++){
      offset += this->menu_entries[i].deserialize(inbuffer + offset);
      }
      uint32_t controls_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      controls_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      controls_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      controls_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      controls.resize(controls_lengthT);
      for( uint32_t i = 0; i < controls.size(); i++){
      offset += this->controls[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarker"; };
    const char * getMD5(){ return "311bd5f6cd6a20820ac0ba84315f4e22"; };

  };

}
#endif