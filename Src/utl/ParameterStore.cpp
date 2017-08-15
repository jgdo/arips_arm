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
	static ParameterEntryImpl<float> pid_p = 50, pid_i = 0.3, pid_d = 200, setpoint = 0.0;
	
	static std::array<ParameterEntry*, PS_ID_END> entries = {&pid_p, &pid_i, &pid_d, &setpoint};
	return entries;
}

} /* namespace utl */
