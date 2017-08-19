/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2009-2010, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/**

 Author: Blaise Gassend

 Handles synchronizing node state with the configuration server, and
 handling of services to get and set configuration.

 */

#ifndef __UTL_PARAMETER_STORE_H__
#define __UTL_PARAMETER_STORE_H__

#include <ros.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/Reconfigure.h>

/**
 * @todo Add diagnostics.
 */

#define DECL_PARAM_NAME(C, T, M, d, mi, ma) template<> struct UtlParamNameTraits<C, T, &C::M> { \
    static constexpr const char* name() { return #M;} \
    static constexpr T MIN_VALUE = mi;\
    static constexpr T MAX_VALUE = ma;\
    static constexpr T DEFAULT_VALUE = d;\
    }

template<class C, class T, T C::* M>
struct UtlParamNameTraits;

template<class C>
struct UtlParamList;

namespace utl {

template<class T>
const char* getParamTypeName();


template<class T>
void addParamToConfig(const char* name, T value, dynamic_reconfigure::Config& paramList);

template<class T, class C, T C::* M>
struct MemberParam {
	static constexpr const char* getName() {
		return UtlParamNameTraits<C, T, M>::name();
	}
	
	static constexpr T getMin() {
		return UtlParamNameTraits<C, T, M>::MIN_VALUE;
	}
	static constexpr T getMax() {
		return UtlParamNameTraits<C, T, M>::MAX_VALUE;
	}
	static constexpr T getDefault() {
		return UtlParamNameTraits<C, T, M>::DEFAULT_VALUE;
	}
	
	typedef T ParamType;

	static void setValue(C* obj, T value) {
		obj->*M = value;
	}
	
	static T getValue(const C* obj) {
		return obj->*M;
	}
};

template<class ...Params>
struct ParamPack;

template<class First, class ...Rest>
struct ParamPack<First, Rest...> {
	static constexpr size_t NUM_PARAMS = 1 + sizeof...(Rest);

	static void fillParamDescriptionList(std::vector<dynamic_reconfigure::ParamDescription>& paramList) {
		paramList.resize(NUM_PARAMS);
		fillParamDescriptionList_(paramList.data());
	}

	static void fillParamDescriptionList_(dynamic_reconfigure::ParamDescription* paramPtr) {
		paramPtr->name = First::getName();
		paramPtr->type = getParamTypeName<typename First::ParamType>();
		paramPtr->level = 0;
		paramPtr->description = "";
		paramPtr->edit_method = "";

		ParamPack<Rest...>::fillParamDescriptionList_(paramPtr+1);
	}

	static void resetParamList(dynamic_reconfigure::Config& paramList) {
		paramList.groups.resize(1);
		paramList.groups[0].name = "Default";
		paramList.groups[0].state = true;
		paramList.groups[0].id = 0;
		paramList.groups[0].parent = 0;

		paramList.bools.resize(0);
		paramList.ints.resize(0);
		paramList.doubles.resize(0);
		paramList.strs.resize(0);
	}

	// ----------- value
	
	template<class C>
	static void fillParamValueList(const C* obj, dynamic_reconfigure::Config& paramList) {
		resetParamList(paramList);
		fillParamValueList_(obj, paramList);
	}

	template<class C>
	static void fillParamValueList_(const C* obj, dynamic_reconfigure::Config& paramList) {
		addParamToConfig<typename First::ParamType>(First::getName(), First::getValue(obj), paramList);
		ParamPack<Rest...>::fillParamValueList_(obj, paramList);
	}

	//------------------ min
	
	static void fillParamMinList(dynamic_reconfigure::Config& paramList) {
		resetParamList(paramList);
		fillParamMinList_(paramList);
	}

	static void fillParamMinList_(dynamic_reconfigure::Config& paramList) {
		addParamToConfig<typename First::ParamType>(First::getName(), First::getMin(), paramList);
		ParamPack<Rest...>::fillParamMinList_(paramList);
	}

	// -------------------- max
	static void fillParamMaxList(dynamic_reconfigure::Config& paramList) {
		resetParamList(paramList);
		fillParamMaxList_(paramList);
	}

	static void fillParamMaxList_(dynamic_reconfigure::Config& paramList) {
		addParamToConfig<typename First::ParamType>(First::getName(), First::getMax(), paramList);
		ParamPack<Rest...>::fillParamMaxList_(paramList);
	}

	// ----------------- default
	static void fillParamDefaultList(dynamic_reconfigure::Config& paramList) {
		resetParamList(paramList);
		fillParamDefaultList_(paramList);
	}

	static void fillParamDefaultList_(dynamic_reconfigure::Config& paramList) {
		addParamToConfig<typename First::ParamType>(First::getName(), First::getDefault(), paramList);
		ParamPack<Rest...>::fillParamDefaultList_(paramList);
	}

	// ------------------- set param
	
	template<class C, class TList>
	static void setFromParamValueListTyped(C* obj, TList const& list) {
		for(auto const& param: list) {
			setFromParamValueList_(obj, param.name, param.value);
		}
	}

	template<class C>
	static void setFromParamValueList(C* obj, const dynamic_reconfigure::Config& paramList) {
		setFromParamValueListTyped(obj, paramList.ints);
		setFromParamValueListTyped(obj, paramList.doubles);
	}

	template<class C, class T>
	static void setFromParamValueList_(C* obj, const char* name, T value) {
		if(strcmp(First::getName(), name) == 0) {
			First::setValue(obj, value);
		} else {
			ParamPack<Rest...>::setFromParamValueList_(obj, name, value);
		}
	}
};

template<>
struct ParamPack<> {
	static constexpr size_t NUM_PARAMS = 0;

	static void fillParamDescriptionList_(dynamic_reconfigure::ParamDescription*) {
	}
	
	template<class C>
	static void fillParamValueList_(const C*, dynamic_reconfigure::Config&) {
	}
	
	static void fillParamMinList_(dynamic_reconfigure::Config&) {
	}
	static void fillParamMaxList_(dynamic_reconfigure::Config&) {
	}
	static void fillParamDefaultList_(dynamic_reconfigure::Config&) {
	}
	
	template<class C, class T>
	static void setFromParamValueList_(C*, const char*, T) { /* TODO error msg param not found */
	}
	
};

/**
 * Keeps track of the reconfigure callback function.
 */
template<class ConfigType>
class ParameterServer {
public:
	ParameterServer() :
			set_service_("set_parameters", &ParameterServer::setConfigCallback, this), 
			update_pub_("parameter_updates", &update_msg), 
			descr_pub_("parameter_descriptions", &descr_msg) {
		init();
	}
	
	// TODO typedef boost::function<void(ConfigType &, uint32_t level)> CallbackType;
	
	/* 
	 void setCallback(const CallbackType &callback)
	 {
	 callback_ = callback;
	 callCallback(config_, ~0); // At startup we need to load the configuration with all level bits set. (Everything has changed.)
	 updateConfigInternal(config_);
	 } */

	void updateConfig(const ConfigType &config) {
		updateConfigInternal(config);
	}
	
	void getConfig(ConfigType &config) const {
		config = config_;
	}
	
	/*

	 void getConfigMax(ConfigType &config)
	 {
	 config = max_;
	 }

	 void getConfigMin(ConfigType &config)
	 {
	 config = min_;
	 }

	 void getConfigDefault(ConfigType &config)
	 {
	 config = default_;
	 }

	 void setConfigMax(const ConfigType &config)
	 {
	 max_ = config;
	 PublishDescription();
	 }

	 void setConfigMin(const ConfigType &config)
	 {
	 min_ = config;
	 PublishDescription();
	 }

	 void setConfigDefault(const ConfigType &config)
	 {
	 default_ = config;
	 PublishDescription();
	 } */

private:
	ros::ServiceServer<dynamic_reconfigure::Reconfigure::Request, dynamic_reconfigure::Reconfigure::Response,
	    ParameterServer> set_service_;

	dynamic_reconfigure::Config update_msg;
	dynamic_reconfigure::ConfigDescription descr_msg;

	ros::Publisher update_pub_;
	ros::Publisher descr_pub_;
	// TODO CallbackType callback_;
	ConfigType config_;
	/*
	 ConfigType min_;
	 ConfigType max_;
	 ConfigType default_; */

	void PublishDescription() {
		//Copy over min_ max_ default_
		dynamic_reconfigure::ConfigDescription description_message;
		// fill groups
		description_message.groups.resize(1);
		description_message.groups[0].name = "Default";
		description_message.groups[0].type = "";
		UtlParamList<ConfigType>::List::fillParamDescriptionList(description_message.groups[0].parameters);
		description_message.groups[0].parent = 0;
		description_message.groups[0].id = 0;
		
		UtlParamList<ConfigType>::List::fillParamMinList(description_message.min);
		UtlParamList<ConfigType>::List::fillParamMaxList(description_message.max);
		UtlParamList<ConfigType>::List::fillParamDefaultList(description_message.dflt);
		
		//Publish description
		descr_pub_.publish(&description_message);
	}
	
	void init() {
		//Grab copys of the data from the config files.  These are declared in the generated config file.
		
		// TODO min, max, default
		/*
		 min_ = ConfigType::__getMin__();
		 max_ = ConfigType::__getMax__();
		 default_ = ConfigType::__getDefault__(); */

		ros::nh.advertiseService<dynamic_reconfigure::Reconfigure::Request, dynamic_reconfigure::Reconfigure::Response,
		    ParameterServer>(set_service_);
		
		ros::nh.advertise(descr_pub_);
		ros::nh.advertise(update_pub_);
		
		ConfigType init_config;
		// TODO init config type
		/*
		 = ConfigType::__getDefault__();
		 init_config.__fromServer__(node_handle_);
		 init_config.__clamp__(); */
		updateConfigInternal(init_config);
	}
	
	void callCallback(ConfigType &config, int level) {
		/* 
		 if (callback_) // At startup we need to load the configuration with all level bits set. (Everything has changed.)
		 {  try {
		 callback_(config, level);
		 }
		 catch (std::exception &e)
		 {
		 ROS_WARN("Reconfigure callback failed with exception %s: ", e.what());
		 }
		 catch (...)
		 {
		 ROS_WARN("Reconfigure callback failed with unprintable exception.");
		 }
		 } */
	}
	
	void setConfigCallback(const dynamic_reconfigure::Reconfigure::Request &req,
	    dynamic_reconfigure::Reconfigure::Response &rsp) {
		ConfigType new_config = config_;
		
		UtlParamList<ConfigType>::List::setFromParamValueList(&new_config, req.config);
		
		// TODO clamp new_config.__clamp__();
		// TODO level uint32_t level = config_.__level__(new_config);
		
		callCallback(new_config, 0 /*level*/);
		
		updateConfigInternal(new_config);
		
		UtlParamList<ConfigType>::List::fillParamValueList(&new_config, rsp.config);
		update_pub_.publish(&rsp.config);
	}
	
	void updateConfigInternal(const ConfigType &config) {
		config_ = config;
		// TODO config_.__toServer__(node_handle_);
		// set parameter on server
		
		UtlParamList<ConfigType>::List::fillParamValueList(&config_, update_msg);
		update_pub_.publish(&update_msg);
	}
};

} // namespace utl

#endif // __UTL_PARAMETER_STORE_H__
