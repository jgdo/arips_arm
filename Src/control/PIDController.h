/*
 * PIDController.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_PIDCONTROLLER_H_
#define CONTROL_PIDCONTROLLER_H_

#include <control/Controller.h>

namespace ctrl {

class PIDController: public Controller {
public:
	virtual float control(float input, float setpoint) override;
};

} /* namespace ctrl */

#endif /* CONTROL_PIDCONTROLLER_H_ */
