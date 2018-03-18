#ifndef _ROS_SERVICE_GetParameterGroups_h
#define _ROS_SERVICE_GetParameterGroups_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/ParameterGroupDef.h"

namespace arips_arm_msgs
{

static const char GETPARAMETERGROUPS[] = "arips_arm_msgs/GetParameterGroups";

  class GetParameterGroupsRequest : public ros::Msg
  {
    public:

    GetParameterGroupsRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETPARAMETERGROUPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetParameterGroupsResponse : public ros::Msg
  {
    public:
      uint32_t groups_length;
      typedef arips_arm_msgs::ParameterGroupDef _groups_type;
      _groups_type st_groups;
      _groups_type * groups;

    GetParameterGroupsResponse():
      groups_length(0), groups(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->groups_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->groups_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->groups_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->groups_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->groups_length);
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t groups_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->groups_length);
      if(groups_lengthT > groups_length)
        this->groups = (arips_arm_msgs::ParameterGroupDef*)realloc(this->groups, groups_lengthT * sizeof(arips_arm_msgs::ParameterGroupDef));
      groups_length = groups_lengthT;
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->st_groups.deserialize(inbuffer + offset);
        memcpy( &(this->groups[i]), &(this->st_groups), sizeof(arips_arm_msgs::ParameterGroupDef));
      }
     return offset;
    }

    const char * getType(){ return GETPARAMETERGROUPS; };
    const char * getMD5(){ return "541e332ce1a9870241bfa0d91d09bfcc"; };

  };

  class GetParameterGroups {
    public:
    typedef GetParameterGroupsRequest Request;
    typedef GetParameterGroupsResponse Response;
  };

}
#endif
