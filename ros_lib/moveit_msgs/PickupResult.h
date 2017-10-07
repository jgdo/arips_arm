#ifndef _ROS_moveit_msgs_PickupResult_h
#define _ROS_moveit_msgs_PickupResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "moveit_msgs/MoveItErrorCodes.h"
#include "moveit_msgs/RobotState.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "moveit_msgs/Grasp.h"

namespace moveit_msgs
{

  class PickupResult : public ros::Msg
  {
    public:
      typedef moveit_msgs::MoveItErrorCodes _error_code_type;
      _error_code_type error_code;
      typedef moveit_msgs::RobotState _trajectory_start_type;
      _trajectory_start_type trajectory_start;
      std::vector<moveit_msgs::RobotTrajectory> trajectory_stages;
      std::vector<char*> trajectory_descriptions;
      typedef moveit_msgs::Grasp _grasp_type;
      _grasp_type grasp;

    PickupResult():
      error_code(),
      trajectory_start(),
      trajectory_stages(),
      trajectory_descriptions(),
      grasp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      offset += this->trajectory_start.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->trajectory_stages.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_stages.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_stages.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_stages.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < trajectory_stages.size(); i++){
      offset += this->trajectory_stages[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->trajectory_descriptions.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_descriptions.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_descriptions.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_descriptions.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < trajectory_descriptions.size(); i++){
      uint32_t length_trajectory_descriptionsi = strlen(this->trajectory_descriptions[i]);
      varToArr(outbuffer + offset, length_trajectory_descriptionsi);
      offset += 4;
      memcpy(outbuffer + offset, this->trajectory_descriptions[i], length_trajectory_descriptionsi);
      offset += length_trajectory_descriptionsi;
      }
      offset += this->grasp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      offset += this->trajectory_start.deserialize(inbuffer + offset);
      uint32_t trajectory_stages_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_stages_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_stages_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_stages_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      trajectory_stages.resize(trajectory_stages_lengthT);
      for( uint32_t i = 0; i < trajectory_stages.size(); i++){
      offset += this->trajectory_stages[i].deserialize(inbuffer + offset);
      }
      uint32_t trajectory_descriptions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_descriptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_descriptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_descriptions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      trajectory_descriptions.resize(trajectory_descriptions_lengthT);
      for( uint32_t i = 0; i < trajectory_descriptions.size(); i++){
      uint32_t length_trajectory_descriptionsi;
      arrToVar(length_trajectory_descriptionsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_trajectory_descriptionsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_trajectory_descriptionsi-1]=0;
      this->trajectory_descriptions[i] = (char *)(inbuffer + offset-1);
      offset += length_trajectory_descriptionsi;
      }
      offset += this->grasp.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "moveit_msgs/PickupResult"; };
    const char * getMD5(){ return "23c6d8bf0580f4bc8f7a8e1f59b4b6b7"; };

  };

}
#endif