#ifndef _ROS_SERVICE_ListControllerTypes_h
#define _ROS_SERVICE_ListControllerTypes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace controller_manager_msgs
{

static const char LISTCONTROLLERTYPES[] = "controller_manager_msgs/ListControllerTypes";

  class ListControllerTypesRequest : public ros::Msg
  {
    public:

    ListControllerTypesRequest()
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

    const char * getType(){ return LISTCONTROLLERTYPES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListControllerTypesResponse : public ros::Msg
  {
    public:
      std::vector<char*> types;
      std::vector<char*> base_classes;

    ListControllerTypesResponse():
      types(),
      base_classes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->types.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->types.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->types.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->types.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < types.size(); i++){
      uint32_t length_typesi = strlen(this->types[i]);
      varToArr(outbuffer + offset, length_typesi);
      offset += 4;
      memcpy(outbuffer + offset, this->types[i], length_typesi);
      offset += length_typesi;
      }
      *(outbuffer + offset + 0) = (this->base_classes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->base_classes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->base_classes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->base_classes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < base_classes.size(); i++){
      uint32_t length_base_classesi = strlen(this->base_classes[i]);
      varToArr(outbuffer + offset, length_base_classesi);
      offset += 4;
      memcpy(outbuffer + offset, this->base_classes[i], length_base_classesi);
      offset += length_base_classesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t types_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      types_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      types_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      types_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      types.resize(types_lengthT);
      for( uint32_t i = 0; i < types.size(); i++){
      uint32_t length_typesi;
      arrToVar(length_typesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_typesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_typesi-1]=0;
      this->types[i] = (char *)(inbuffer + offset-1);
      offset += length_typesi;
      }
      uint32_t base_classes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      base_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      base_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      base_classes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      base_classes.resize(base_classes_lengthT);
      for( uint32_t i = 0; i < base_classes.size(); i++){
      uint32_t length_base_classesi;
      arrToVar(length_base_classesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_base_classesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_base_classesi-1]=0;
      this->base_classes[i] = (char *)(inbuffer + offset-1);
      offset += length_base_classesi;
      }
     return offset;
    }

    const char * getType(){ return LISTCONTROLLERTYPES; };
    const char * getMD5(){ return "c1d4cd11aefa9f97ba4aeb5b33987f4e"; };

  };

  class ListControllerTypes {
    public:
    typedef ListControllerTypesRequest Request;
    typedef ListControllerTypesResponse Response;
  };

}
#endif
