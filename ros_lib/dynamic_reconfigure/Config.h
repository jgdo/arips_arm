#ifndef _ROS_dynamic_reconfigure_Config_h
#define _ROS_dynamic_reconfigure_Config_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "dynamic_reconfigure/BoolParameter.h"
#include "dynamic_reconfigure/IntParameter.h"
#include "dynamic_reconfigure/StrParameter.h"
#include "dynamic_reconfigure/DoubleParameter.h"
#include "dynamic_reconfigure/GroupState.h"

namespace dynamic_reconfigure
{

  class Config : public ros::Msg
  {
    public:
      std::vector<dynamic_reconfigure::BoolParameter> bools;
      std::vector<dynamic_reconfigure::IntParameter> ints;
      std::vector<dynamic_reconfigure::StrParameter> strs;
      std::vector<dynamic_reconfigure::DoubleParameter> doubles;
      std::vector<dynamic_reconfigure::GroupState> groups;

    Config():
      bools(),
      ints(),
      strs(),
      doubles(),
      groups()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->bools.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bools.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bools.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bools.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < bools.size(); i++){
      offset += this->bools[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->ints.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ints.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ints.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ints.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < ints.size(); i++){
      offset += this->ints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->strs.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->strs.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->strs.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->strs.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < strs.size(); i++){
      offset += this->strs[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->doubles.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->doubles.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->doubles.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->doubles.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < doubles.size(); i++){
      offset += this->doubles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->groups.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->groups.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->groups.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->groups.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < groups.size(); i++){
      offset += this->groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t bools_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bools_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bools_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bools_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      bools.resize(bools_lengthT);
      for( uint32_t i = 0; i < bools.size(); i++){
      offset += this->bools[i].deserialize(inbuffer + offset);
      }
      uint32_t ints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      ints.resize(ints_lengthT);
      for( uint32_t i = 0; i < ints.size(); i++){
      offset += this->ints[i].deserialize(inbuffer + offset);
      }
      uint32_t strs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      strs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      strs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      strs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      strs.resize(strs_lengthT);
      for( uint32_t i = 0; i < strs.size(); i++){
      offset += this->strs[i].deserialize(inbuffer + offset);
      }
      uint32_t doubles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      doubles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      doubles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      doubles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      doubles.resize(doubles_lengthT);
      for( uint32_t i = 0; i < doubles.size(); i++){
      offset += this->doubles[i].deserialize(inbuffer + offset);
      }
      uint32_t groups_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      groups.resize(groups_lengthT);
      for( uint32_t i = 0; i < groups.size(); i++){
      offset += this->groups[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "dynamic_reconfigure/Config"; };
    const char * getMD5(){ return "958f16a05573709014982821e6822580"; };

  };

}
#endif