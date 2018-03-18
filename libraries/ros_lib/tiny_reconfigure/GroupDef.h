#ifndef _ROS_tiny_reconfigure_GroupDef_h
#define _ROS_tiny_reconfigure_GroupDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace tiny_reconfigure
{

  class GroupDef : public ros::Msg
  {
    public:
      typedef uint8_t _group_id_type;
      _group_id_type group_id;
      typedef uint8_t _num_groups_type;
      _num_groups_type num_groups;
      typedef const char* _group_name_type;
      _group_name_type group_name;

    GroupDef():
      group_id(0),
      num_groups(0),
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->group_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->group_id);
      *(outbuffer + offset + 0) = (this->num_groups >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_groups);
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->group_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->group_id);
      this->num_groups =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_groups);
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return "tiny_reconfigure/GroupDef"; };
    const char * getMD5(){ return "92496c3a1de5f410f6e56467054b07ed"; };

  };

}
#endif