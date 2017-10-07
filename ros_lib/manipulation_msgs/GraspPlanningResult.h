#ifndef _ROS_manipulation_msgs_GraspPlanningResult_h
#define _ROS_manipulation_msgs_GraspPlanningResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "manipulation_msgs/Grasp.h"
#include "manipulation_msgs/GraspPlanningErrorCode.h"

namespace manipulation_msgs
{

  class GraspPlanningResult : public ros::Msg
  {
    public:
      std::vector<manipulation_msgs::Grasp> grasps;
      typedef manipulation_msgs::GraspPlanningErrorCode _error_code_type;
      _error_code_type error_code;

    GraspPlanningResult():
      grasps(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->grasps.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grasps.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grasps.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grasps.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < grasps.size(); i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t grasps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      grasps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      grasps.resize(grasps_lengthT);
      for( uint32_t i = 0; i < grasps.size(); i++){
      offset += this->grasps[i].deserialize(inbuffer + offset);
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspPlanningResult"; };
    const char * getMD5(){ return "ff7a88c4aec40207164535a24dc9c440"; };

  };

}
#endif