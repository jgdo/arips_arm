#ifndef _ROS_rosapi_TypeDef_h
#define _ROS_rosapi_TypeDef_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace rosapi
{

  class TypeDef : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      std::vector<char*> fieldnames;
      std::vector<char*> fieldtypes;
      std::vector<int32_t> fieldarraylen;
      std::vector<char*> examples;

    TypeDef():
      type(""),
      fieldnames(),
      fieldtypes(),
      fieldarraylen(),
      examples()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->fieldnames.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fieldnames.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fieldnames.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fieldnames.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fieldnames.size(); i++){
      uint32_t length_fieldnamesi = strlen(this->fieldnames[i]);
      varToArr(outbuffer + offset, length_fieldnamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->fieldnames[i], length_fieldnamesi);
      offset += length_fieldnamesi;
      }
      *(outbuffer + offset + 0) = (this->fieldtypes.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fieldtypes.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fieldtypes.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fieldtypes.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fieldtypes.size(); i++){
      uint32_t length_fieldtypesi = strlen(this->fieldtypes[i]);
      varToArr(outbuffer + offset, length_fieldtypesi);
      offset += 4;
      memcpy(outbuffer + offset, this->fieldtypes[i], length_fieldtypesi);
      offset += length_fieldtypesi;
      }
      *(outbuffer + offset + 0) = (this->fieldarraylen.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fieldarraylen.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fieldarraylen.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fieldarraylen.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fieldarraylen.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_fieldarrayleni;
      u_fieldarrayleni.real = this->fieldarraylen[i];
      *(outbuffer + offset + 0) = (u_fieldarrayleni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fieldarrayleni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fieldarrayleni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fieldarrayleni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fieldarraylen[i]);
      }
      *(outbuffer + offset + 0) = (this->examples.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->examples.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->examples.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->examples.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < examples.size(); i++){
      uint32_t length_examplesi = strlen(this->examples[i]);
      varToArr(outbuffer + offset, length_examplesi);
      offset += 4;
      memcpy(outbuffer + offset, this->examples[i], length_examplesi);
      offset += length_examplesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t fieldnames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fieldnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fieldnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fieldnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fieldnames.resize(fieldnames_lengthT);
      for( uint32_t i = 0; i < fieldnames.size(); i++){
      uint32_t length_fieldnamesi;
      arrToVar(length_fieldnamesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fieldnamesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fieldnamesi-1]=0;
      this->fieldnames[i] = (char *)(inbuffer + offset-1);
      offset += length_fieldnamesi;
      }
      uint32_t fieldtypes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fieldtypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fieldtypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fieldtypes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fieldtypes.resize(fieldtypes_lengthT);
      for( uint32_t i = 0; i < fieldtypes.size(); i++){
      uint32_t length_fieldtypesi;
      arrToVar(length_fieldtypesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fieldtypesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fieldtypesi-1]=0;
      this->fieldtypes[i] = (char *)(inbuffer + offset-1);
      offset += length_fieldtypesi;
      }
      uint32_t fieldarraylen_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fieldarraylen_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fieldarraylen_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fieldarraylen_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fieldarraylen.resize(fieldarraylen_lengthT);
      for( uint32_t i = 0; i < fieldarraylen.size(); i++){
      union {
        int32_t real;
        uint32_t base;
      } u_fieldarrayleni;
      u_fieldarrayleni.base = 0;
      u_fieldarrayleni.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fieldarrayleni.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fieldarrayleni.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fieldarrayleni.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fieldarraylen[i] = u_fieldarrayleni.real;
      offset += sizeof(this->fieldarraylen[i]);
      }
      uint32_t examples_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      examples_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      examples_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      examples_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      examples.resize(examples_lengthT);
      for( uint32_t i = 0; i < examples.size(); i++){
      uint32_t length_examplesi;
      arrToVar(length_examplesi, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_examplesi; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_examplesi-1]=0;
      this->examples[i] = (char *)(inbuffer + offset-1);
      offset += length_examplesi;
      }
     return offset;
    }

    const char * getType(){ return "rosapi/TypeDef"; };
    const char * getMD5(){ return "bd8529b0edb168fde8dd58032743f1f7"; };

  };

}
#endif