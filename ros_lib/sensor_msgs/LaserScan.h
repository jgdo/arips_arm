#ifndef _ROS_sensor_msgs_LaserScan_h
#define _ROS_sensor_msgs_LaserScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class LaserScan : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _angle_min_type;
      _angle_min_type angle_min;
      typedef float _angle_max_type;
      _angle_max_type angle_max;
      typedef float _angle_increment_type;
      _angle_increment_type angle_increment;
      typedef float _time_increment_type;
      _time_increment_type time_increment;
      typedef float _scan_time_type;
      _scan_time_type scan_time;
      typedef float _range_min_type;
      _range_min_type range_min;
      typedef float _range_max_type;
      _range_max_type range_max;
      std::vector<float> ranges;
      std::vector<float> intensities;

    LaserScan():
      header(),
      angle_min(0),
      angle_max(0),
      angle_increment(0),
      time_increment(0),
      scan_time(0),
      range_min(0),
      range_max(0),
      ranges(),
      intensities()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle_min;
      u_angle_min.real = this->angle_min;
      *(outbuffer + offset + 0) = (u_angle_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_min);
      union {
        float real;
        uint32_t base;
      } u_angle_max;
      u_angle_max.real = this->angle_max;
      *(outbuffer + offset + 0) = (u_angle_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_max);
      union {
        float real;
        uint32_t base;
      } u_angle_increment;
      u_angle_increment.real = this->angle_increment;
      *(outbuffer + offset + 0) = (u_angle_increment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_increment.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_increment.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_increment.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_increment);
      union {
        float real;
        uint32_t base;
      } u_time_increment;
      u_time_increment.real = this->time_increment;
      *(outbuffer + offset + 0) = (u_time_increment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_increment.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_increment.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_increment.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_increment);
      union {
        float real;
        uint32_t base;
      } u_scan_time;
      u_scan_time.real = this->scan_time;
      *(outbuffer + offset + 0) = (u_scan_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scan_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scan_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scan_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_time);
      union {
        float real;
        uint32_t base;
      } u_range_min;
      u_range_min.real = this->range_min;
      *(outbuffer + offset + 0) = (u_range_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_min);
      union {
        float real;
        uint32_t base;
      } u_range_max;
      u_range_max.real = this->range_max;
      *(outbuffer + offset + 0) = (u_range_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_max);
      *(outbuffer + offset + 0) = (this->ranges.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ranges.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ranges.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ranges.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < ranges.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_rangesi;
      u_rangesi.real = this->ranges[i];
      *(outbuffer + offset + 0) = (u_rangesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rangesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rangesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rangesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ranges[i]);
      }
      *(outbuffer + offset + 0) = (this->intensities.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->intensities.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->intensities.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->intensities.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < intensities.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_intensitiesi;
      u_intensitiesi.real = this->intensities[i];
      *(outbuffer + offset + 0) = (u_intensitiesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intensitiesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intensitiesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intensitiesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensities[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle_min;
      u_angle_min.base = 0;
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_min = u_angle_min.real;
      offset += sizeof(this->angle_min);
      union {
        float real;
        uint32_t base;
      } u_angle_max;
      u_angle_max.base = 0;
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_max = u_angle_max.real;
      offset += sizeof(this->angle_max);
      union {
        float real;
        uint32_t base;
      } u_angle_increment;
      u_angle_increment.base = 0;
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_increment = u_angle_increment.real;
      offset += sizeof(this->angle_increment);
      union {
        float real;
        uint32_t base;
      } u_time_increment;
      u_time_increment.base = 0;
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_increment = u_time_increment.real;
      offset += sizeof(this->time_increment);
      union {
        float real;
        uint32_t base;
      } u_scan_time;
      u_scan_time.base = 0;
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scan_time = u_scan_time.real;
      offset += sizeof(this->scan_time);
      union {
        float real;
        uint32_t base;
      } u_range_min;
      u_range_min.base = 0;
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_min = u_range_min.real;
      offset += sizeof(this->range_min);
      union {
        float real;
        uint32_t base;
      } u_range_max;
      u_range_max.base = 0;
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_max = u_range_max.real;
      offset += sizeof(this->range_max);
      uint32_t ranges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      ranges.resize(ranges_lengthT);
      for( uint32_t i = 0; i < ranges.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_rangesi;
      u_rangesi.base = 0;
      u_rangesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rangesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rangesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rangesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ranges[i] = u_rangesi.real;
      offset += sizeof(this->ranges[i]);
      }
      uint32_t intensities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      intensities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      intensities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      intensities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      intensities.resize(intensities_lengthT);
      for( uint32_t i = 0; i < intensities.size(); i++){
      union {
        float real;
        uint32_t base;
      } u_intensitiesi;
      u_intensitiesi.base = 0;
      u_intensitiesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intensitiesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intensitiesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intensitiesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->intensities[i] = u_intensitiesi.real;
      offset += sizeof(this->intensities[i]);
      }
     return offset;
    }

    const char * getType(){ return "sensor_msgs/LaserScan"; };
    const char * getMD5(){ return "90c7ef2dc6895d81024acba2ac42f369"; };

  };

}
#endif