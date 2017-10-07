#ifndef _ROS_moveit_msgs_AllowedCollisionMatrix_h
#define _ROS_moveit_msgs_AllowedCollisionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/AllowedCollisionEntry.h"

namespace moveit_msgs
{

  class AllowedCollisionMatrix : public ros::Msg
  {
    public:
      std::vector<char*> entry_names;
      std::vector<moveit_msgs::AllowedCollisionEntry> entry_values;
      std::vector<char*> default_entry_names;
      std::vector<bool> default_entry_values;

    AllowedCollisionMatrix():
      entry_names(),
      entry_values(),
      default_entry_names(),
      default_entry_values()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->entry_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entry_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entry_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entry_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < entry_names.size(); i++){
      uint32_t length_entry_namesi = strlen(this->entry_names[i]);
      varToArr(outbuffer + offset, length_entry_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->entry_names[i], length_entry_namesi);
      offset += length_entry_namesi;
      }
      *(outbuffer + offset + 0) = (this->entry_values.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entry_values.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entry_values.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entry_values.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < entry_values.size(); i++){
      offset += this->entry_values[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->default_entry_names.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->default_entry_names.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->default_entry_names.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->default_entry_names.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < default_entry_names.size(); i++){
      uint32_t length_default_entry_namesi = strlen(this->default_entry_names[i]);
      varToArr(outbuffer + offset, length_default_entry_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->default_entry_names[i], length_default_entry_namesi);
      offset += length_default_entry_namesi;
      }
      *(outbuffer + offset + 0) = (this->default_entry_values.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->default_entry_values.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->default_entry_values.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->default_entry_values.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < default_entry_values.size(); i++){
      union {
        bool real;
        uint8_t base;
      } u_default_entry_valuesi;
      u_default_entry_valuesi.real = this->default_entry_values[i];
      *(outbuffer + offset + 0) = (u_default_entry_valuesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->default_entry_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t entry_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      entry_names.resize(entry_names_lengthT);
      for( uint32_t i = 0; i < entry_names.size(); i++){
      uint32_t length_entry_namesi;
      arrToVar(length_entry_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_entry_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_entry_namesi-1]=0;
      this->entry_names[i] = (char *)(inbuffer + offset-1);
      offset += length_entry_namesi;
      }
      uint32_t entry_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      entry_values.resize(entry_values_lengthT);
      for( uint32_t i = 0; i < entry_values.size(); i++){
      offset += this->entry_values[i].deserialize(inbuffer + offset);
      }
      uint32_t default_entry_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      default_entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      default_entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      default_entry_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      default_entry_names.resize(default_entry_names_lengthT);
      for( uint32_t i = 0; i < default_entry_names.size(); i++){
      uint32_t length_default_entry_namesi;
      arrToVar(length_default_entry_namesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_default_entry_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_default_entry_namesi-1]=0;
      this->default_entry_names[i] = (char *)(inbuffer + offset-1);
      offset += length_default_entry_namesi;
      }
      uint32_t default_entry_values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      default_entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      default_entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      default_entry_values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      default_entry_values.resize(default_entry_values_lengthT);
      for( uint32_t i = 0; i < default_entry_values.size(); i++){
      union {
        bool real;
        uint8_t base;
      } u_default_entry_valuesi;
      u_default_entry_valuesi.base = 0;
      u_default_entry_valuesi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->default_entry_values[i] = u_default_entry_valuesi.real;
      offset += sizeof(this->default_entry_values[i]);
      }
     return offset;
    }

    const char * getType(){ return "moveit_msgs/AllowedCollisionMatrix"; };
    const char * getMD5(){ return "aedce13587eef0d79165a075659c1879"; };

  };

}
#endif