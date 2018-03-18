#ifndef _ROS_arips_arm_msgs_TrajectoryBufferCommand_h
#define _ROS_arips_arm_msgs_TrajectoryBufferCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arips_arm_msgs/TrajectoryPoint.h"

namespace arips_arm_msgs
{

  class TrajectoryBufferCommand : public ros::Msg
  {
    public:
      typedef uint32_t _start_index_type;
      _start_index_type start_index;
      typedef uint32_t _size_type;
      _size_type size;
      arips_arm_msgs::TrajectoryPoint traj_points[10];

    TrajectoryBufferCommand():
      start_index(0),
      size(0),
      traj_points()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->start_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_index);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      for( uint32_t i = 0; i < 10; i++){
      offset += this->traj_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->start_index =  ((uint32_t) (*(inbuffer + offset)));
      this->start_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_index);
      this->size =  ((uint32_t) (*(inbuffer + offset)));
      this->size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size);
      for( uint32_t i = 0; i < 10; i++){
      offset += this->traj_points[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "arips_arm_msgs/TrajectoryBufferCommand"; };
    const char * getMD5(){ return "1909df88293e4497feff79ee4974e9f5"; };

  };

}
#endif