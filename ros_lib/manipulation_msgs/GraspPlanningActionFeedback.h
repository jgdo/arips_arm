#ifndef _ROS_manipulation_msgs_GraspPlanningActionFeedback_h
#define _ROS_manipulation_msgs_GraspPlanningActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "manipulation_msgs/GraspPlanningFeedback.h"

namespace manipulation_msgs
{

  class GraspPlanningActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef manipulation_msgs::GraspPlanningFeedback _feedback_type;
      _feedback_type feedback;

    GraspPlanningActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "manipulation_msgs/GraspPlanningActionFeedback"; };
    const char * getMD5(){ return "25a75a7c3117e1e7efda49b65ff22a06"; };

  };

}
#endif