/*
 * Actuator.hpp
 *
 *  Created on: Jun 25, 2017
 *      Author: jgdo
 */

#ifndef CONTROL_ACTUATOR_HPP_
#define CONTROL_ACTUATOR_HPP_

struct Actuator {
	virtual ~Actuator() {}
	
	virtual void set(float value) = 0;
	virtual const char* name() const = 0;
};


#endif /* CONTROL_ACTUATOR_HPP_ */
