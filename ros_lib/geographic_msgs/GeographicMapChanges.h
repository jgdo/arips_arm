#ifndef _ROS_geographic_msgs_GeographicMapChanges_h
#define _ROS_geographic_msgs_GeographicMapChanges_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeographicMap.h"
#include "uuid_msgs/UniqueID.h"

namespace geographic_msgs
{

  class GeographicMapChanges : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geographic_msgs::GeographicMap _diffs_type;
      _diffs_type diffs;
      std::vector<uuid_msgs::UniqueID> deletes;

    GeographicMapChanges():
      header(),
      diffs(),
      deletes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->diffs.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->deletes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deletes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deletes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deletes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < deletes.size(); i++){
      offset += this->deletes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->diffs.deserialize(inbuffer + offset);
      uint32_t deletes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      deletes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      deletes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      deletes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      deletes.resize(deletes_lengthT);
      for( uint32_t i = 0; i < deletes.size(); i++){
      offset += this->deletes[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "geographic_msgs/GeographicMapChanges"; };
    const char * getMD5(){ return "4fd027f54298203ec12aa1c4b20e6cb8"; };

  };

}
#endif