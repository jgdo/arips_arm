/*
 * Controller.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_CONTROLLER_H_
#define CONTROL_CONTROLLER_H_

namespace ctrl {

template<class T>
class Controller {
public:
	typedef T ValueType;
	
	virtual ~Controller() {}
	
	virtual void reset() {}
	
	virtual float computeControl(ValueType input, ValueType setpoint) = 0;
};

};


#endif /* CONTROL_CONTROLLER_H_ */
