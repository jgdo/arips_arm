#ifndef _ROS_arips_arm_msgs_ParameterGroupDef_h
#define _ROS_arips_arm_msgs_ParameterGroupDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class ParameterGroupDef : public ros::Msg
  {
    public:
      typedef const char* _groupname_type;
      _groupname_type groupname;

    ParameterGroupDef():
      groupname("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_groupname = strlen(this->groupname);
      varToArr(outbuffer + offset, length_groupname);
      offset += 4;
      memcpy(outbuffer + offset, this->groupname, length_groupname);
      offset += length_groupname;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_groupname;
      arrToVar(length_groupname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_groupname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_groupname-1]=0;
      this->groupname = (char *)(inbuffer + offset-1);
      offset += length_groupname;
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/ParameterGroupDef"; };
    const char * getMD5(){ return "9a9c967a9ae053af7b30436546917e94"; };

  };

}
#endif