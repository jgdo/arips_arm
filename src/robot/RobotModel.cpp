/*
 * RobotModel.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: jgdo
 */

#include <robot/RobotModel.h>

namespace robot {

RobotModel::RobotModel() {
}

const JointLimits& RobotModel::getJointLimits() const {
	static const JointLimits limits = { 
			JointLimit {-2, 2},
			JointLimit {-2, 2},
			JointLimit {-2, 2},
			JointLimit {-2, 2},
			JointLimit {-2, 2}
	};
	
	return limits;
}

} /* namespace robot */
