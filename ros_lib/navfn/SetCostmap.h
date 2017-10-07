#ifndef _ROS_SERVICE_SetCostmap_h
#define _ROS_SERVICE_SetCostmap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace navfn
{

static const char SETCOSTMAP[] = "navfn/SetCostmap";

  class SetCostmapRequest : public ros::Msg
  {
    public:
      std::vector<uint8_t> costs;
      typedef uint16_t _height_type;
      _height_type height;
      typedef uint16_t _width_type;
      _width_type width;

    SetCostmapRequest():
      costs(),
      height(0),
      width(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->costs.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->costs.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->costs.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->costs.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < costs.size(); i++){
      *(outbuffer + offset + 0) = (this->costs[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->costs[i]);
      }
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->width);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t costs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      costs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      costs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      costs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      costs.resize(costs_lengthT);
      for( uint32_t i = 0; i < costs.size(); i++){
      this->costs[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->costs[i]);
      }
      this->height =  ((uint16_t) (*(inbuffer + offset)));
      this->height |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->height);
      this->width =  ((uint16_t) (*(inbuffer + offset)));
      this->width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->width);
     return offset;
    }

    const char * getType(){ return SETCOSTMAP; };
    const char * getMD5(){ return "370ec969cdb71f9cde7c7cbe0d752308"; };

  };

  class SetCostmapResponse : public ros::Msg
  {
    public:

    SetCostmapResponse()
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

    const char * getType(){ return SETCOSTMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetCostmap {
    public:
    typedef SetCostmapRequest Request;
    typedef SetCostmapResponse Response;
  };

}
#endif
