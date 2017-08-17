#ifndef _ROS_diagnostic_msgs_DiagnosticArray_h
#define _ROS_diagnostic_msgs_DiagnosticArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "diagnostic_msgs/DiagnosticStatus.h"

namespace diagnostic_msgs
{

  class DiagnosticArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<diagnostic_msgs::DiagnosticStatus> status;

    DiagnosticArray():
      header(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < status.size(); i++){
      offset += this->status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      status.resize(status_lengthT);
      for( uint32_t i = 0; i < status.size(); i++){
      offset += this->status[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "diagnostic_msgs/DiagnosticArray"; };
    const char * getMD5(){ return "60810da900de1dd6ddd437c3503511da"; };

  };

}
#endif