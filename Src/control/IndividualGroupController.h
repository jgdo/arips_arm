/*
 * IndividualGroupController.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jgdo
 */

#ifndef CONTROL_INDIVIDUALGROUPCONTROLLER_H_
#define CONTROL_INDIVIDUALGROUPCONTROLLER_H_

#include "GroupController.h"

namespace ctrl {

template<class T, size_t N>
class IndividualGroupController: public GroupController<T, N> {
public:
	IndividualGroupController(std::array<ctrl::Controller<T>*, N> const& controllers): mControllers(controllers) {
	}
	
	virtual void reset() {
		for(auto& c: mControllers) {
			c->reset();
		}
	}
		
	virtual std::array<float, N> computeControl(std::array<T, N> const& inputs, std::array<T, N> const& setpoints) {
		std::array<float, N> output;
		for(size_t i = 0; i < N; i++) {
			output.at(i) = mControllers.at(i)->computeControl(inputs.at(i), setpoints.at(i));
		}
		
		return output;
	}
	
private:
	std::array<ctrl::Controller<T>*, N> mControllers;
};

} // namespace ctrl


#endif /* CONTROL_INDIVIDUALGROUPCONTROLLER_H_ */
