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
		sub("parameter", &ROSParameterStoreHandler::parameterCallback, this) {
	// ros::nh.subscribe(sub);
}

void utl::ROSParameterStoreHandler::parameterCallback(const arips_arm_msgs::parameter& p) {
	//ParameterStore::setFromString((ParameterStoreEntryID)p.id, p.value);
	
	// ros::nh.loginfo("parameterCallback()");
}
