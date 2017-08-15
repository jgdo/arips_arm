/*
 * ROSParameterStoreHandler.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#include <utl/ROSParameterStoreHandler.h>

namespace utl {

} /* namespace utl */

utl::ROSParameterStoreHandler::ROSParameterStoreHandler() :
		paramService("set_parameter", &ROSParameterStoreHandler::parameterCallback, this) {
	ros::nh.advertiseService(paramService);
}

void utl::ROSParameterStoreHandler::parameterCallback(const arips_arm_msgs::SetParameterRequest& req,
		arips_arm_msgs::SetParameterResponse& res) {
	
	res.result = ParameterStore::setFromString((ParameterStoreEntryID)req.id, req.value);
}
