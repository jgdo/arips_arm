#ifndef _ROS_smach_msgs_SmachContainerStructure_h
#define _ROS_smach_msgs_SmachContainerStructure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace smach_msgs
{

  class SmachContainerStructure : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _path_type;
      _path_type path;
      std::vector<char*> children;
      std::vector<char*> internal_outcomes;
      std::vector<char*> outcomes_from;
      std::vector<char*> outcomes_to;
      std::vector<char*> container_outcomes;

    SmachContainerStructure():
      header(),
      path(""),
      children(),
      internal_outcomes(),
      outcomes_from(),
      outcomes_to(),
      container_outcomes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_path = strlen(this->path);
      varToArr(outbuffer + offset, length_path);
      offset += 4;
      memcpy(outbuffer + offset, this->path, length_path);
      offset += length_path;
      *(outbuffer + offset + 0) = (this->children.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->children.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->children.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->children.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < children.size(); i++){
      uint32_t length_childreni = strlen(this->children[i]);
      varToArr(outbuffer + offset, length_childreni);
      offset += 4;
      memcpy(outbuffer + offset, this->children[i], length_childreni);
      offset += length_childreni;
      }
      *(outbuffer + offset + 0) = (this->internal_outcomes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->internal_outcomes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->internal_outcomes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->internal_outcomes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < internal_outcomes.size(); i++){
      uint32_t length_internal_outcomesi = strlen(this->internal_outcomes[i]);
      varToArr(outbuffer + offset, length_internal_outcomesi);
      offset += 4;
      memcpy(outbuffer + offset, this->internal_outcomes[i], length_internal_outcomesi);
      offset += length_internal_outcomesi;
      }
      *(outbuffer + offset + 0) = (this->outcomes_from.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->outcomes_from.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->outcomes_from.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->outcomes_from.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < outcomes_from.size(); i++){
      uint32_t length_outcomes_fromi = strlen(this->outcomes_from[i]);
      varToArr(outbuffer + offset, length_outcomes_fromi);
      offset += 4;
      memcpy(outbuffer + offset, this->outcomes_from[i], length_outcomes_fromi);
      offset += length_outcomes_fromi;
      }
      *(outbuffer + offset + 0) = (this->outcomes_to.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->outcomes_to.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->outcomes_to.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->outcomes_to.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < outcomes_to.size(); i++){
      uint32_t length_outcomes_toi = strlen(this->outcomes_to[i]);
      varToArr(outbuffer + offset, length_outcomes_toi);
      offset += 4;
      memcpy(outbuffer + offset, this->outcomes_to[i], length_outcomes_toi);
      offset += length_outcomes_toi;
      }
      *(outbuffer + offset + 0) = (this->container_outcomes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->container_outcomes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->container_outcomes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->container_outcomes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < container_outcomes.size(); i++){
      uint32_t length_container_outcomesi = strlen(this->container_outcomes[i]);
      varToArr(outbuffer + offset, length_container_outcomesi);
      offset += 4;
      memcpy(outbuffer + offset, this->container_outcomes[i], length_container_outcomesi);
      offset += length_container_outcomesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_path;
      arrToVar(length_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_path-1]=0;
      this->path = (char *)(inbuffer + offset-1);
      offset += length_path;
      uint32_t children_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      children_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      children_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      children_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      children.resize(children_lengthT);
      for( uint32_t i = 0; i < children.size(); i++){
      uint32_t length_childreni;
      arrToVar(length_childreni, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_childreni; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_childreni-1]=0;
      this->children[i] = (char *)(inbuffer + offset-1);
      offset += length_childreni;
      }
      uint32_t internal_outcomes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      internal_outcomes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      internal_outcomes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      internal_outcomes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      internal_outcomes.resize(internal_outcomes_lengthT);
      for( uint32_t i = 0; i < internal_outcomes.size(); i++){
      uint32_t length_internal_outcomesi;
      arrToVar(length_internal_outcomesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_internal_outcomesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_internal_outcomesi-1]=0;
      this->internal_outcomes[i] = (char *)(inbuffer + offset-1);
      offset += length_internal_outcomesi;
      }
      uint32_t outcomes_from_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      outcomes_from_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      outcomes_from_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      outcomes_from_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      outcomes_from.resize(outcomes_from_lengthT);
      for( uint32_t i = 0; i < outcomes_from.size(); i++){
      uint32_t length_outcomes_fromi;
      arrToVar(length_outcomes_fromi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_outcomes_fromi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_outcomes_fromi-1]=0;
      this->outcomes_from[i] = (char *)(inbuffer + offset-1);
      offset += length_outcomes_fromi;
      }
      uint32_t outcomes_to_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      outcomes_to_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      outcomes_to_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      outcomes_to_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      outcomes_to.resize(outcomes_to_lengthT);
      for( uint32_t i = 0; i < outcomes_to.size(); i++){
      uint32_t length_outcomes_toi;
      arrToVar(length_outcomes_toi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_outcomes_toi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_outcomes_toi-1]=0;
      this->outcomes_to[i] = (char *)(inbuffer + offset-1);
      offset += length_outcomes_toi;
      }
      uint32_t container_outcomes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      container_outcomes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      container_outcomes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      container_outcomes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      container_outcomes.resize(container_outcomes_lengthT);
      for( uint32_t i = 0; i < container_outcomes.size(); i++){
      uint32_t length_container_outcomesi;
      arrToVar(length_container_outcomesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_container_outcomesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_container_outcomesi-1]=0;
      this->container_outcomes[i] = (char *)(inbuffer + offset-1);
      offset += length_container_outcomesi;
      }
     return offset;
    }

    const char * getType(){ return "smach_msgs/SmachContainerStructure"; };
    const char * getMD5(){ return "3d3d1e0d0f99779ee9e58101a5dcf7ea"; };

  };

}
#endif