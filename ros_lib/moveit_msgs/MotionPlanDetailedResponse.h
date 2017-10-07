#ifndef _ROS_moveit_msgs_MotionPlanDetailedResponse_h
#define _ROS_moveit_msgs_MotionPlanDetailedResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/MoveItErrorCodes.h"

namespace moveit_msgs
{

  class MotionPlanDetailedResponse : public ros::Msg
  {
    public:
      typedef moveit_msgs::RobotState _trajectory_start_type;
      _trajectory_start_type trajectory_start;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      std::vector<moveit_msgs::RobotTrajectory> trajectory;
      std::vector<char*> description;
      std::vector<float> processing_time;
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;

    MotionPlanDetailedResponse():
      trajectory_start(),
      group_name(""),
      trajectory(),
      description(),
      processing_time(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory_start.serialize(outbuffer + offset);
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      *(outbuffer + offset + 0) = (this->trajectory.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < trajectory.size(); i++){
      offset += this->trajectory[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->description.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->description.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->description.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->description.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < description.size(); i++){
      uint32_t length_descriptioni = strlen(this->description[i]);
      varToArr(outbuffer + offset, length_descriptioni);
      offset += 4;
      memcpy(outbuffer + offset, this->description[i], length_descriptioni);
      offset += length_descriptioni;
      }
      *(outbuffer + offset + 0) = (this->processing_time.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->processing_time.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->processing_time.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->processing_time.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < processing_time.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->processing_time[i]);
      }
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory_start.deserialize(inbuffer + offset);
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      uint32_t trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      trajectory.resize(trajectory_lengthT);
      for( uint32_t i = 0; i < trajectory.size(); i++){
      offset += this->trajectory[i].deserialize(inbuffer + offset);
      }
      uint32_t description_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      description_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      description_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      description_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      description.resize(description_lengthT);
      for( uint32_t i = 0; i < description.size(); i++){
      uint32_t length_descriptioni;
      arrToVar(length_descriptioni, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_descriptioni; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_descriptioni-1]=0;
      this->description[i] = (char *)(inbuffer + offset-1);
      offset += length_descriptioni;
      }
      uint32_t processing_time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      processing_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      processing_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      processing_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      processing_time.resize(processing_time_lengthT);
      for( uint32_t i = 0; i < processing_time.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->processing_time[i]));
      }
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/MotionPlanDetailedResponse"; };
    const char * getMD5(){ return "7b84c374bb2e37bdc0eba664f7636a8f"; };

  };

}
#endif