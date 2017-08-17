#ifndef _ROS_theora_image_transport_Packet_h
#define _ROS_theora_image_transport_Packet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace theora_image_transport
{

  class Packet : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      std::vector<uint8_t> data;
      typedef int32_t _b_o_s_type;
      _b_o_s_type b_o_s;
      typedef int32_t _e_o_s_type;
      _e_o_s_type e_o_s;
      typedef int64_t _granulepos_type;
      _granulepos_type granulepos;
      typedef int64_t _packetno_type;
      _packetno_type packetno;

    Packet():
      header(),
      data(),
      b_o_s(0),
      e_o_s(0),
      granulepos(0),
      packetno(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < data.size(); i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_b_o_s;
      u_b_o_s.real = this->b_o_s;
      *(outbuffer + offset + 0) = (u_b_o_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b_o_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b_o_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b_o_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_o_s);
      union {
        int32_t real;
        uint32_t base;
      } u_e_o_s;
      u_e_o_s.real = this->e_o_s;
      *(outbuffer + offset + 0) = (u_e_o_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_e_o_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_e_o_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_e_o_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->e_o_s);
      union {
        int64_t real;
        uint64_t base;
      } u_granulepos;
      u_granulepos.real = this->granulepos;
      *(outbuffer + offset + 0) = (u_granulepos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_granulepos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_granulepos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_granulepos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_granulepos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_granulepos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_granulepos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_granulepos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->granulepos);
      union {
        int64_t real;
        uint64_t base;
      } u_packetno;
      u_packetno.real = this->packetno;
      *(outbuffer + offset + 0) = (u_packetno.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packetno.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packetno.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packetno.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_packetno.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_packetno.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_packetno.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_packetno.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->packetno);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      data.resize(data_lengthT);
      for( uint32_t i = 0; i < data.size(); i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_b_o_s;
      u_b_o_s.base = 0;
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b_o_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b_o_s = u_b_o_s.real;
      offset += sizeof(this->b_o_s);
      union {
        int32_t real;
        uint32_t base;
      } u_e_o_s;
      u_e_o_s.base = 0;
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_e_o_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->e_o_s = u_e_o_s.real;
      offset += sizeof(this->e_o_s);
      union {
        int64_t real;
        uint64_t base;
      } u_granulepos;
      u_granulepos.base = 0;
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_granulepos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->granulepos = u_granulepos.real;
      offset += sizeof(this->granulepos);
      union {
        int64_t real;
        uint64_t base;
      } u_packetno;
      u_packetno.base = 0;
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_packetno.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->packetno = u_packetno.real;
      offset += sizeof(this->packetno);
     return offset;
    }

    const char * getType(){ return "theora_image_transport/Packet"; };
    const char * getMD5(){ return "33ac4e14a7cff32e7e0d65f18bb410f3"; };

  };

}
#endif