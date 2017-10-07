#ifndef _ROS_manipulation_msgs_PlaceLocation_h
#define _ROS_manipulation_msgs_PlaceLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/PoseStamped.h"
#include "manipulation_msgs/GripperTranslation.h"

namespace manipulation_msgs
{

  class PlaceLocation : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef sensor_msgs::JointState _post_place_posture_type;
      _post_place_posture_type post_place_posture;
      typedef geometry_msgs::PoseStamped _place_pose_type;
      _place_pose_type place_pose;
      typedef manipulation_msgs::GripperTranslation _approach_type;
      _approach_type approach;
      typedef manipulation_msgs::GripperTranslation _retreat_type;
      _retreat_type retreat;
      std::vector<char*> allowed_touch_objects;

    PlaceLocation():
      id(""),
      post_place_posture(),
      place_pose(),
      approach(),
      retreat(),
      allowed_touch_objects()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->post_place_posture.serialize(outbuffer + offset);
      offset += this->place_pose.serialize(outbuffer + offset);
      offset += this->approach.serialize(outbuffer + offset);
      offset += this->retreat.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->allowed_touch_objects.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_touch_objects.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_touch_objects.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_touch_objects.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < allowed_touch_objects.size(); i++){
      uint32_t length_allowed_touch_objectsi = strlen(this->allowed_touch_objects[i]);
      varToArr(outbuffer + offset, length_allowed_touch_objectsi);
      offset += 4;
      memcpy(outbuffer + offset, this->allowed_touch_objects[i], length_allowed_touch_objectsi);
      offset += length_allowed_touch_objectsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->post_place_posture.deserialize(inbuffer + offset);
      offset += this->place_pose.deserialize(inbuffer + offset);
      offset += this->approach.deserialize(inbuffer + offset);
      offset += this->retreat.deserialize(inbuffer + offset);
      uint32_t allowed_touch_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      allowed_touch_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      allowed_touch_objects.resize(allowed_touch_objects_lengthT);
      for( uint32_t i = 0; i < allowed_touch_objects.size(); i++){
      uint32_t length_allowed_touch_objectsi;
      arrToVar(length_allowed_touch_objectsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_allowed_touch_objectsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_allowed_touch_objectsi-1]=0;
      this->allowed_touch_objects[i] = (char *)(inbuffer + offset-1);
      offset += length_allowed_touch_objectsi;
      }
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/PlaceLocation"; };
    const char * getMD5(){ return "0139dab9852add0e64233c5fb3b8a25a"; };

  };

}
#endif