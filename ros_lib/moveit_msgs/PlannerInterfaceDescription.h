#ifndef _ROS_moveit_msgs_PlannerInterfaceDescription_h
#define _ROS_moveit_msgs_PlannerInterfaceDescription_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace moveit_msgs
{

  class PlannerInterfaceDescription : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      std::vector<char*> planner_ids;

    PlannerInterfaceDescription():
      name(""),
      planner_ids()
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
      *(outbuffer + offset + 0) = (this->planner_ids.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planner_ids.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planner_ids.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planner_ids.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < planner_ids.size(); i++){
      uint32_t length_planner_idsi = strlen(this->planner_ids[i]);
      varToArr(outbuffer + offset, length_planner_idsi);
      offset += 4;
      memcpy(outbuffer + offset, this->planner_ids[i], length_planner_idsi);
      offset += length_planner_idsi;
      }
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
      uint32_t planner_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      planner_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      planner_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      planner_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      planner_ids.resize(planner_ids_lengthT);
      for( uint32_t i = 0; i < planner_ids.size(); i++){
      uint32_t length_planner_idsi;
      arrToVar(length_planner_idsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_idsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_idsi-1]=0;
      this->planner_ids[i] = (char *)(inbuffer + offset-1);
      offset += length_planner_idsi;
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PlannerInterfaceDescription"; };
    const char * getMD5(){ return "ea5f6e6129aa1b110ccda9900d2bf25e"; };

  };

}
#endif