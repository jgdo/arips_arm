#ifndef _ROS_geographic_msgs_RouteSegment_h
#define _ROS_geographic_msgs_RouteSegment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "geographic_msgs/KeyValue.h"

namespace geographic_msgs
{

  class RouteSegment : public ros::Msg
  {
    public:
      typedef uuid_msgs::UniqueID _id_type;
      _id_type id;
      typedef uuid_msgs::UniqueID _start_type;
      _start_type start;
      typedef uuid_msgs::UniqueID _end_type;
      _end_type end;
      std::vector<geographic_msgs::KeyValue> props;

    RouteSegment():
      id(),
      start(),
      end(),
      props()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      offset += this->start.serialize(outbuffer + offset);
      offset += this->end.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->props.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->props.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->props.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->props.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < props.size(); i++){
      offset += this->props[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->end.deserialize(inbuffer + offset);
      uint32_t props_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      props_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      props_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      props_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      props.resize(props_lengthT);
      for( uint32_t i = 0; i < props.size(); i++){
      offset += this->props[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "geographic_msgs/RouteSegment"; };
    const char * getMD5(){ return "8583d1e2ddf1891c3934a5d2ed9a799c"; };

  };

}
#endif