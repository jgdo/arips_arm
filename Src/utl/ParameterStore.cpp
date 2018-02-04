/*
 * ParameterStore.cpp
 *
 *  Created on: Aug 19, 2017
 *      Author: jgdo
 */

#if 0
#include "ParameterStore.h"

namespace utl {

template<>
const char* getParamTypeName<int>() {
	return "int";
}

template<>
const char* getParamTypeName<double>() {
	return "double";
}

template<>
const char* getParamTypeName<float>() {
	return "double";
}

template<>
void addParamToConfig<int>(const char* name, int value, dynamic_reconfigure::Config& paramList) {
	paramList.ints.resize(paramList.ints.size() + 1);
	paramList.ints.back().name = name;
	paramList.ints.back().value = value;
}

template<>
void addParamToConfig<float>(const char* name, float value, dynamic_reconfigure::Config& paramList) {
	paramList.doubles.resize(paramList.doubles.size() + 1);
	paramList.doubles.back().name = name;
	paramList.doubles.back().value = value;
}

template<>
void addParamToConfig<double>(const char* name, double value, dynamic_reconfigure::Config& paramList) {
	paramList.doubles.resize(paramList.doubles.size() + 1);
	paramList.doubles.back().name = name;
	paramList.doubles.back().value = value;
}

}

#endif
