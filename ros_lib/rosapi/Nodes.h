#ifndef _ROS_SERVICE_Nodes_h
#define _ROS_SERVICE_Nodes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

static const char NODES[] = "rosapi/Nodes";

  class NodesRequest : public ros::Msg
  {
    public:

    NodesRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return NODES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NodesResponse : public ros::Msg
  {
    public:
      std::vector<char*> nodes;

    NodesResponse():
      nodes()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->nodes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < nodes.size(); i++){
      uint32_t length_nodesi = strlen(this->nodes[i]);
      varToArr(outbuffer + offset, length_nodesi);
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_nodesi);
      offset += length_nodesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      nodes.resize(nodes_lengthT);
      for( uint32_t i = 0; i < nodes.size(); i++){
      uint32_t length_nodesi;
      arrToVar(length_nodesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nodesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nodesi-1]=0;
      this->nodes[i] = (char *)(inbuffer + offset-1);
      offset += length_nodesi;
      }
     return offset;
    }

    const char * getType(){ return NODES; };
    const char * getMD5(){ return "3d07bfda1268b4f76b16b7ba8a82665d"; };

  };

  class Nodes {
    public:
    typedef NodesRequest Request;
    typedef NodesResponse Response;
  };

}
#endif