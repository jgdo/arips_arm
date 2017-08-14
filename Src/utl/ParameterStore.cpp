/*
 * ParameterStore.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#include <utl/ParameterStore.h>

#include <control/PIDController.h>

namespace utl {

std::array<ParameterEntry*, PS_ID_END>& ParameterStore::storeEntries() {
	static ParameterEntryImpl<float> pid_p = 3, pid_i = 0.005, pid_d = 15;
	
	static std::array<ParameterEntry*, PS_ID_END> entries = {&pid_p, &pid_i, &pid_d};
	return entries;
}

} /* namespace utl */
