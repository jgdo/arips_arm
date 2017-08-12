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
	
	virtual void set(float value) = 0;
	virtual const char* name() const = 0;
};

}

#endif /* HW_ACTUATOR_HPP_ */
