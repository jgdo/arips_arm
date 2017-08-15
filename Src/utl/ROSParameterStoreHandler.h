/*
 * ROSParameterStoreHandler.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef UTL_ROSPARAMETERSTOREHANDLER_H_
#define UTL_ROSPARAMETERSTOREHANDLER_H_

#include "ParameterStore.h"

#include <arips_arm_msgs/SetParameter.h>
#include <ros.h>

namespace utl {

class ROSParameterStoreHandler {
public:
	ROSParameterStoreHandler();
	
protected:
	// ros::Publisher pub;
	// ros::Subscriber<arips_arm_msgs::parameter, ROSParameterStoreHandler> sub;
	
	ros::ServiceServer<arips_arm_msgs::SetParameterRequest,
		arips_arm_msgs::SetParameterResponse, ROSParameterStoreHandler> paramService;

	void parameterCallback(const arips_arm_msgs::SetParameterRequest& req, arips_arm_msgs::SetParameterResponse& res);
};

} /* namespace utl */

#endif /* UTL_ROSPARAMETERSTOREHANDLER_H_ */
