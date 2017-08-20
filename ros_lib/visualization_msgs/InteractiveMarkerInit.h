#ifndef _ROS_visualization_msgs_InteractiveMarkerInit_h
#define _ROS_visualization_msgs_InteractiveMarkerInit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "visualization_msgs/InteractiveMarker.h"

namespace visualization_msgs
{

  class InteractiveMarkerInit : public ros::Msg
  {
    public:
      typedef const char* _server_id_type;
      _server_id_type server_id;
      typedef uint64_t _seq_num_type;
      _seq_num_type seq_num;
      std::vector<visualization_msgs::InteractiveMarker> markers;

    InteractiveMarkerInit():
      server_id(""),
      seq_num(0),
      markers()
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
      *(outbuffer + offset + 0) = (this->markers.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < markers.size(); i++){
      offset += this->markers[i].serialize(outbuffer + offset);
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
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      markers.resize(markers_lengthT);
      for( uint32_t i = 0; i < markers.size(); i++){
      offset += this->markers[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "visualization_msgs/InteractiveMarkerInit"; };
    const char * getMD5(){ return "aa2f1dcea79533d1710675195653028d"; };

  };

}
#endif