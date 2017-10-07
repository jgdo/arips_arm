#ifndef _ROS_object_recognition_msgs_TableArray_h
#define _ROS_object_recognition_msgs_TableArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "object_recognition_msgs/Table.h"

namespace object_recognition_msgs
{

  class TableArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<object_recognition_msgs::Table> tables;

    TableArray():
      header(),
      tables()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->tables.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tables.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tables.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tables.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < tables.size(); i++){
      offset += this->tables[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t tables_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tables_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tables_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tables_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      tables.resize(tables_lengthT);
      for( uint32_t i = 0; i < tables.size(); i++){
      offset += this->tables[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "object_recognition_msgs/TableArray"; };
    const char * getMD5(){ return "d1c853e5acd0ed273eb6682dc01ab428"; };

  };

}
#endif