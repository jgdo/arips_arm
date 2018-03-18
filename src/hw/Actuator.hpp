/*
 * Actuator.hpp
 *
 *  Created on: Jun 25, 2017
 *      Author: jgdo
 */

#ifndef HW_ACTUATOR_HPP_
#define HW_ACTUATOR_HPP_

namespace hw {


struct Actuator {
	virtual ~Actuator() {}
	
	virtual const char* name() const = 0;
	
	/**
	 * break the motors (e.g. by short-cutting)
	 */
	virtual void doBreak() = 0;
	
	/**
	 * Make motors free-running
	 */
	virtual void release() = 0;
	
	/**
	 * Activate motor and apply power
	 * 
	 * @param value power, [-1, 1] (unit not specified)
	 * @return power actually applied
	 */
	virtual float apply(float value) = 0;
};

}

#endif /* HW_ACTUATOR_HPP_ */
