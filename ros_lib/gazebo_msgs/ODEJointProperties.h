#ifndef _ROS_gazebo_msgs_ODEJointProperties_h
#define _ROS_gazebo_msgs_ODEJointProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"

namespace gazebo_msgs
{

  class ODEJointProperties : public ros::Msg
  {
    public:
      std::vector<float> damping;
      std::vector<float> hiStop;
      std::vector<float> loStop;
      std::vector<float> erp;
      std::vector<float> cfm;
      std::vector<float> stop_erp;
      std::vector<float> stop_cfm;
      std::vector<float> fudge_factor;
      std::vector<float> fmax;
      std::vector<float> vel;

    ODEJointProperties():
      damping(),
      hiStop(),
      loStop(),
      erp(),
      cfm(),
      stop_erp(),
      stop_cfm(),
      fudge_factor(),
      fmax(),
      vel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->damping.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->damping.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->damping.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->damping.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < damping.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->damping[i]);
      }
      *(outbuffer + offset + 0) = (this->hiStop.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hiStop.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hiStop.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hiStop.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < hiStop.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->hiStop[i]);
      }
      *(outbuffer + offset + 0) = (this->loStop.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loStop.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loStop.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loStop.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < loStop.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->loStop[i]);
      }
      *(outbuffer + offset + 0) = (this->erp.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->erp.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->erp.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->erp.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < erp.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->erp[i]);
      }
      *(outbuffer + offset + 0) = (this->cfm.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cfm.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cfm.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cfm.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < cfm.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->cfm[i]);
      }
      *(outbuffer + offset + 0) = (this->stop_erp.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_erp.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_erp.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_erp.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < stop_erp.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stop_erp[i]);
      }
      *(outbuffer + offset + 0) = (this->stop_cfm.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_cfm.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_cfm.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_cfm.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < stop_cfm.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stop_cfm[i]);
      }
      *(outbuffer + offset + 0) = (this->fudge_factor.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fudge_factor.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fudge_factor.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fudge_factor.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fudge_factor.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->fudge_factor[i]);
      }
      *(outbuffer + offset + 0) = (this->fmax.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fmax.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fmax.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fmax.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < fmax.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->fmax[i]);
      }
      *(outbuffer + offset + 0) = (this->vel.size() >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel.size() >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel.size() >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel.size() >> (8 * 3)) & 0xFF;
      offset += 4;
      for( uint32_t i = 0; i < vel.size(); i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->vel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t damping_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      damping_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      damping_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      damping_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      damping.resize(damping_lengthT);
      for( uint32_t i = 0; i < damping.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->damping[i]));
      }
      uint32_t hiStop_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hiStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hiStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hiStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      hiStop.resize(hiStop_lengthT);
      for( uint32_t i = 0; i < hiStop.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hiStop[i]));
      }
      uint32_t loStop_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      loStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      loStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      loStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      loStop.resize(loStop_lengthT);
      for( uint32_t i = 0; i < loStop.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->loStop[i]));
      }
      uint32_t erp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      erp.resize(erp_lengthT);
      for( uint32_t i = 0; i < erp.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->erp[i]));
      }
      uint32_t cfm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      cfm.resize(cfm_lengthT);
      for( uint32_t i = 0; i < cfm.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cfm[i]));
      }
      uint32_t stop_erp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      stop_erp.resize(stop_erp_lengthT);
      for( uint32_t i = 0; i < stop_erp.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stop_erp[i]));
      }
      uint32_t stop_cfm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      stop_cfm.resize(stop_cfm_lengthT);
      for( uint32_t i = 0; i < stop_cfm.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stop_cfm[i]));
      }
      uint32_t fudge_factor_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fudge_factor_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fudge_factor_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fudge_factor_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fudge_factor.resize(fudge_factor_lengthT);
      for( uint32_t i = 0; i < fudge_factor.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fudge_factor[i]));
      }
      uint32_t fmax_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fmax_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fmax_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fmax_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      fmax.resize(fmax_lengthT);
      for( uint32_t i = 0; i < fmax.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->fmax[i]));
      }
      uint32_t vel_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += 4;
      vel.resize(vel_lengthT);
      for( uint32_t i = 0; i < vel.size(); i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel[i]));
      }
     return offset;
    }

    const char * getType(){ return "gazebo_msgs/ODEJointProperties"; };
    const char * getMD5(){ return "1b744c32a920af979f53afe2f9c3511f"; };

  };

}
#endif