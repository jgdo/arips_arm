/*
 * RobotModel.h
 *
 *  Created on: Feb 18, 2018
 *      Author: jgdo
 */

#ifndef ROBOT_ROBOTMODEL_H_
#define ROBOT_ROBOTMODEL_H_


#include "ArmConfig.h"

namespace robot {

struct JointLimit {
	float minAngle, maxAngle; // radians
};

typedef std::array<JointLimit, ArmConfig::NUM_ARM_JOINTS> JointLimits;

class RobotModel {
public:
	RobotModel();
	
	const JointLimits& getJointLimits() const;
	
private:
};

} /* namespace robot */

#endif /* ROBOT_ROBOTMODEL_H_ */
