#ifndef _ROS_SERVICE_ProjectedMapsInfo_h
#define _ROS_SERVICE_ProjectedMapsInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "map_msgs/ProjectedMapInfo.h"

namespace map_msgs
{

static const char PROJECTEDMAPSINFO[] = "map_msgs/ProjectedMapsInfo";

  class ProjectedMapsInfoRequest : public ros::Msg
  {
    public:
      std::vector<map_msgs::ProjectedMapInfo> projected_maps_info;

    ProjectedMapsInfoRequest():
      projected_maps_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->projected_maps_info.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->projected_maps_info.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->projected_maps_info.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->projected_maps_info.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < projected_maps_info.size(); i++){
      offset += this->projected_maps_info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t projected_maps_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      projected_maps_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      projected_maps_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      projected_maps_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      projected_maps_info.resize(projected_maps_info_lengthT);
      for( uint32_t i = 0; i < projected_maps_info.size(); i++){
      offset += this->projected_maps_info[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return PROJECTEDMAPSINFO; };
    const char * getMD5(){ return "d7980a33202421c8cd74565e57a4d229"; };

  };

  class ProjectedMapsInfoResponse : public ros::Msg
  {
    public:

    ProjectedMapsInfoResponse()
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

    const char * getType(){ return PROJECTEDMAPSINFO; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ProjectedMapsInfo {
    public:
    typedef ProjectedMapsInfoRequest Request;
    typedef ProjectedMapsInfoResponse Response;
  };

}
#endif
