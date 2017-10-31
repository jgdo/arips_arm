#ifndef _ROS_visualization_msgs_InteractiveMarkerUpdate_h
#define _ROS_visualization_msgs_InteractiveMarkerUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "visualization_msgs/InteractiveMarker.h"
#include "visualization_msgs/InteractiveMarkerPose.h"

namespace visualization_msgs
{

  class InteractiveMarkerUpdate : public ros::Msg
  {
    public:
      typedef const char* _server_id_type;
      _server_id_type server_id;
      typedef uint64_t _seq_num_type;
      _seq_num_type seq_num;
      typedef uint8_t _type_type;
      _type_type type;
      std::vector<visualization_msgs::InteractiveMarker> markers;
      std::vector<visualization_msgs::InteractiveMarkerPose> poses;
      std::vector<char*> erases;
      enum { KEEP_ALIVE =  0 };
      enum { UPDATE =  1 };

    InteractiveMarkerUpdate():
      server_id(""),
      seq_num(0),
      type(0),
      markers(),
      poses(),
      erases()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_server_id = strlen(this->server_id);
      varToArr(outbuffer + offset, length_server_id);
      offset += 4;
      memcpy(outbuffer + offset, this->server_id, length_server_id);
      offset += length_server_id;
      union {
        uint64_t real;
        uint32_t base;
      } u_seq_num;
      u_seq_num.real = this->seq_num;
      *(outbuffer + offset + 0) = (u_seq_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_seq_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_seq_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_seq_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seq_num);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->markers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < markers.size(); i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->poses.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < poses.size(); i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->erases.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->erases.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->erases.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->erases.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < erases.size(); i++){
      uint32_t length_erasesi = strlen(this->erases[i]);
      varToArr(outbuffer + offset, length_erasesi);
      offset += 4;
      memcpy(outbuffer + offset, this->erases[i], length_erasesi);
      offset += length_erasesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_server_id;
      arrToVar(length_server_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_server_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_server_id-1]=0;
      this->server_id = (char *)(inbuffer + offset-1);
      offset += length_server_id;
      union {
        uint64_t real;
        uint32_t base;
      } u_seq_num;
      u_seq_num.base = 0;
      u_seq_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_seq_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_seq_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_seq_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seq_num = u_seq_num.real;
      offset += sizeof(this->seq_num);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      markers.resize(markers_lengthT);
      for( uint32_t i = 0; i < markers.size(); i++){
      offset += this->markers[i].deserialize(inbuffer + offset);
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      poses.resize(poses_lengthT);
      for( uint32_t i = 0; i < poses.size(); i++){
      offset += this->poses[i].deserialize(inbuffer + offset);
      }
      uint32_t erases_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      erases_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      erases_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      erases_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      erases.resize(erases_lengthT);
      for( uint32_t i = 0; i < erases.size(); i++){
      uint32_t length_erasesi;
      arrToVar(length_erasesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_erasesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_erasesi-1]=0;
      this->erases[i] = (char *)(inbuffer + offset-1);
      offset += length_erasesi;
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarkerUpdate"; };
    const char * getMD5(){ return "710d308d0a9276d65945e92dd30b3946"; };

  };

}
#endif