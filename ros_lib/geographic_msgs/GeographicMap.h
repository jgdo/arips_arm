#ifndef _ROS_geographic_msgs_GeographicMap_h
#define _ROS_geographic_msgs_GeographicMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "uuid_msgs/UniqueID.h"
#include "geographic_msgs/BoundingBox.h"
#include "geographic_msgs/WayPoint.h"
#include "geographic_msgs/MapFeature.h"
#include "geographic_msgs/KeyValue.h"

namespace geographic_msgs
{

  class GeographicMap : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uuid_msgs::UniqueID _id_type;
      _id_type id;
      typedef geographic_msgs::BoundingBox _bounds_type;
      _bounds_type bounds;
      std::vector<geographic_msgs::WayPoint> points;
      std::vector<geographic_msgs::MapFeature> features;
      std::vector<geographic_msgs::KeyValue> props;

    GeographicMap():
      header(),
      id(),
      bounds(),
      points(),
      features(),
      props()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->id.serialize(outbuffer + offset);
      offset += this->bounds.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->points.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < points.size(); i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->features.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->features.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->features.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->features.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < features.size(); i++){
      offset += this->features[i].serialize(outbuffer + offset);
      }
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
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->bounds.deserialize(inbuffer + offset);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      points.resize(points_lengthT);
      for( uint32_t i = 0; i < points.size(); i++){
      offset += this->points[i].deserialize(inbuffer + offset);
      }
      uint32_t features_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      features_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      features_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      features_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      features.resize(features_lengthT);
      for( uint32_t i = 0; i < features.size(); i++){
      offset += this->features[i].deserialize(inbuffer + offset);
      }
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

    const char * getType(){ return "geographic_msgs/GeographicMap"; };
    const char * getMD5(){ return "0f4ce6d2ebf9ac9c7c4f3308f6ae0731"; };

  };

}
#endif