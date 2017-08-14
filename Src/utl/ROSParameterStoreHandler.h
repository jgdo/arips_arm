/*
 * ROSParameterStoreHandler.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef UTL_ROSPARAMETERSTOREHANDLER_H_
#define UTL_ROSPARAMETERSTOREHANDLER_H_

#include "ParameterStore.h"

#include <arips_arm_msgs/parameter.h>
#include <ros.h>

namespace utl {

class ROSParameterStoreHandler {
public:
	ROSParameterStoreHandler();
	
protected:
	// ros::Publisher pub;
	ros::Subscriber<arips_arm_msgs::parameter, ROSParameterStoreHandler> sub;
	
	void parameterCallback(const arips_arm_msgs::parameter& p);
};

} /* namespace utl */

#endif /* UTL_ROSPARAMETERSTOREHANDLER_H_ */
