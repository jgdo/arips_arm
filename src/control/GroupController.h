/*
 * GroupController.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jgdo
 */

#ifndef CONTROL_GROUPCONTROLLER_H_
#define CONTROL_GROUPCONTROLLER_H_

#include <array>

namespace ctrl {

template<class T, size_t N>
class GroupController {
public:
	virtual ~GroupController() {}
	
	virtual void reset() {}
	
	virtual std::array<float, N> computeControl(std::array<T, N> const& inputs, std::array<T, N> const& setpoints) = 0;
};

} /* namespace ctrl */

#endif /* CONTROL_GROUPCONTROLLER_H_ */
