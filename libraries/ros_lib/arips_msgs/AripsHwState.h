#ifndef _ROS_arips_msgs_AripsHwState_h
#define _ROS_arips_msgs_AripsHwState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_msgs
{

  class AripsHwState : public ros::Msg
  {
    public:
      typedef float _kinectTiltAngle_type;
      _kinectTiltAngle_type kinectTiltAngle;
      typedef float _odomX_type;
      _odomX_type odomX;
      typedef float _odomY_type;
      _odomY_type odomY;
      typedef float _odomAngle_type;
      _odomAngle_type odomAngle;

    AripsHwState():
      kinectTiltAngle(0),
      odomX(0),
      odomY(0),
      odomAngle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_kinectTiltAngle;
      u_kinectTiltAngle.real = this->kinectTiltAngle;
      *(outbuffer + offset + 0) = (u_kinectTiltAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kinectTiltAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kinectTiltAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kinectTiltAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kinectTiltAngle);
      offset += serializeAvrFloat64(outbuffer + offset, this->odomX);
      offset += serializeAvrFloat64(outbuffer + offset, this->odomY);
      union {
        float real;
        uint32_t base;
      } u_odomAngle;
      u_odomAngle.real = this->odomAngle;
      *(outbuffer + offset + 0) = (u_odomAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odomAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odomAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odomAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odomAngle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_kinectTiltAngle;
      u_kinectTiltAngle.base = 0;
      u_kinectTiltAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kinectTiltAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kinectTiltAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kinectTiltAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kinectTiltAngle = u_kinectTiltAngle.real;
      offset += sizeof(this->kinectTiltAngle);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->odomX));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->odomY));
      union {
        float real;
        uint32_t base;
      } u_odomAngle;
      u_odomAngle.base = 0;
      u_odomAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odomAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odomAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odomAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odomAngle = u_odomAngle.real;
      offset += sizeof(this->odomAngle);
     return offset;
    }

    const char * getType(){ return "arips_msgs/AripsHwState"; };
    const char * getMD5(){ return "26591d762acc45f00e680f2af0b0827d"; };

  };

}
#endif