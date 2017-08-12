/*
 * Controller.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_CONTROLLER_H_
#define CONTROL_CONTROLLER_H_

namespace ctrl {

class Controller {
public:
	virtual ~Controller() {}
	
	virtual void reset() {}
	virtual float control(float input, float setpoint) = 0;
};

};


#endif /* CONTROL_CONTROLLER_H_ */
