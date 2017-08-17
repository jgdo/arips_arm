#ifndef _ROS_SERVICE_NodeletList_h
#define _ROS_SERVICE_NodeletList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace nodelet
{

static const char NODELETLIST[] = "nodelet/NodeletList";

  class NodeletListRequest : public ros::Msg
  {
    public:

    NodeletListRequest()
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

    const char * getType(){ return NODELETLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NodeletListResponse : public ros::Msg
  {
    public:
      std::vector<char*> nodelets;

    NodeletListResponse():
      nodelets()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->nodelets.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodelets.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodelets.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodelets.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < nodelets.size(); i++){
      uint32_t length_nodeletsi = strlen(this->nodelets[i]);
      varToArr(outbuffer + offset, length_nodeletsi);
      offset += 4;
      memcpy(outbuffer + offset, this->nodelets[i], length_nodeletsi);
      offset += length_nodeletsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t nodelets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodelets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodelets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodelets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      nodelets.resize(nodelets_lengthT);
      for( uint32_t i = 0; i < nodelets.size(); i++){
      uint32_t length_nodeletsi;
      arrToVar(length_nodeletsi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nodeletsi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nodeletsi-1]=0;
      this->nodelets[i] = (char *)(inbuffer + offset-1);
      offset += length_nodeletsi;
      }
     return offset;
    }

    const char * getType(){ return NODELETLIST; };
    const char * getMD5(){ return "99c7b10e794f5600b8030e697e946ca7"; };

  };

  class NodeletList {
    public:
    typedef NodeletListRequest Request;
    typedef NodeletListResponse Response;
  };

}
#endif
