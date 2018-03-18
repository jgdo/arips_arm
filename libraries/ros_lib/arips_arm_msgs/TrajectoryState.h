#ifndef _ROS_arips_arm_msgs_TrajectoryState_h
#define _ROS_arips_arm_msgs_TrajectoryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arips_arm_msgs
{

  class TrajectoryState : public ros::Msg
  {
    public:
      typedef uint32_t _controlCycleCount_type;
      _controlCycleCount_type controlCycleCount;
      typedef uint32_t _numPointsInBuffer_type;
      _numPointsInBuffer_type numPointsInBuffer;
      typedef uint32_t _bufferCapacity_type;
      _bufferCapacity_type bufferCapacity;

    TrajectoryState():
      controlCycleCount(0),
      numPointsInBuffer(0),
      bufferCapacity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->controlCycleCount >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->controlCycleCount >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->controlCycleCount >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->controlCycleCount >> (8 * 3)) & 0xFF;
      offset += sizeof(this->controlCycleCount);
      *(outbuffer + offset + 0) = (this->numPointsInBuffer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->numPointsInBuffer >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->numPointsInBuffer >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->numPointsInBuffer >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numPointsInBuffer);
      *(outbuffer + offset + 0) = (this->bufferCapacity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bufferCapacity >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bufferCapacity >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bufferCapacity >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bufferCapacity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->controlCycleCount =  ((uint32_t) (*(inbuffer + offset)));
      this->controlCycleCount |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->controlCycleCount |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->controlCycleCount |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->controlCycleCount);
      this->numPointsInBuffer =  ((uint32_t) (*(inbuffer + offset)));
      this->numPointsInBuffer |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->numPointsInBuffer |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->numPointsInBuffer |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->numPointsInBuffer);
      this->bufferCapacity =  ((uint32_t) (*(inbuffer + offset)));
      this->bufferCapacity |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bufferCapacity |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bufferCapacity |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->bufferCapacity);
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/TrajectoryState"; };
    const char * getMD5(){ return "67f8e1dd7a27aa39ff23be7d74d461b1"; };

  };

}
#endif