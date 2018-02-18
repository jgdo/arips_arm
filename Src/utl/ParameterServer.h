/*
 * ParameterServer.h
 *
 *  Created on: Feb 4, 2018
 *      Author: jgdo
 */

#ifndef UTL_PARAMETERSERVER_H_
#define UTL_PARAMETERSERVER_H_

#include <ros.h>

#include <tiny_reconfigure/GetDef.h>
#include <tiny_reconfigure/GroupDef.h>
#include <tiny_reconfigure/ParameterDef.h>
#include <tiny_reconfigure/SetParam.h>

namespace utl {

class ParameterGroup;

class Parameter {
public:
	Parameter(const char* name, ParameterGroup* group);
	
	inline virtual  ~Parameter() {
	}
	
	virtual tiny_reconfigure::ParameterDef::_type_type getType() const = 0;
	
	virtual void fillValue(tiny_reconfigure::ParameterDef::_value_int_type* value_int, 
			tiny_reconfigure::ParameterDef::_value_float_type* value_float) const = 0;
	
	virtual void setValue(tiny_reconfigure::ParameterDef::_value_int_type value_int, 
				tiny_reconfigure::ParameterDef::_value_float_type value_float) = 0;
	
	const char* const mName;
	Parameter* mNextParam = nullptr;
};

class IntParam: public Parameter {
public:
	IntParam(const char* name, ParameterGroup* group, int value):
		Parameter(name, group),
		mValue(value)
	{
		
	}
	
	virtual tiny_reconfigure::ParameterDef::_type_type getType() const override {
		return tiny_reconfigure::ParameterDef::TYPE_INT;
	}
	
	virtual void fillValue(tiny_reconfigure::ParameterDef::_value_int_type* value_int, 
			tiny_reconfigure::ParameterDef::_value_float_type*) const override {
		*value_int = mValue;
	}
	
	virtual void setValue(tiny_reconfigure::ParameterDef::_value_int_type value_int, 
					tiny_reconfigure::ParameterDef::_value_float_type) override {
		mValue = value_int;
	}
	
	int mValue;
};

class FloatParam: public Parameter {
public:
	FloatParam(const char* name, ParameterGroup* group, float value):
		Parameter(name, group),
		mValue(value)
	{
		
	}
	
	virtual tiny_reconfigure::ParameterDef::_type_type getType() const override {
		return tiny_reconfigure::ParameterDef::TYPE_FLOAT;
	}
	
	virtual void fillValue(tiny_reconfigure::ParameterDef::_value_int_type*, 
			tiny_reconfigure::ParameterDef::_value_float_type* value_float) const override {
		*value_float = mValue;
	}
	
	virtual void setValue(tiny_reconfigure::ParameterDef::_value_int_type, 
						tiny_reconfigure::ParameterDef::_value_float_type value_float) override {
	mValue = value_float;
}
	
	float mValue;
};

class ParameterGroup {
public:
	ParameterGroup(const char* name);
	
	void registerParameter(Parameter* param);
	
	const char* const mName;
	ParameterGroup* mNextGroup = nullptr;
	Parameter* mFirstParameter = nullptr;
	Parameter* mLastParameter = nullptr;
	tiny_reconfigure::ParameterDef::_num_params_type mNumParams = 0;
};

class ParameterServer {
public:    
    static void registerParameterGroup(ParameterGroup* group);

    static void init() {
    	ros::nh.advertise(sTheParameterServer.mGroupDefPub);
			ros::nh.advertise(sTheParameterServer.mParamDefPub);
			ros::nh.subscribe(sTheParameterServer.mGetDefSub);
			ros::nh.advertiseService(sTheParameterServer.mSetParamSrv);
    }
private:    
    static ParameterServer sTheParameterServer;
    
    static ParameterGroup* sAllGroupsFirst;
    static ParameterGroup* sAllGroupsLast;
    static tiny_reconfigure::GroupDef::_num_groups_type sNumGroups;
    
    tiny_reconfigure::GroupDef mGroupDefMsg;
    ros::Publisher mGroupDefPub;
    tiny_reconfigure::ParameterDef mParamDefMsg;
    ros::Publisher mParamDefPub;

    ros::Subscriber<tiny_reconfigure::GetDef, ParameterServer> mGetDefSub;
    ros::ServiceServer<tiny_reconfigure::SetParamRequest, tiny_reconfigure::SetParamResponse, ParameterServer> mSetParamSrv;
    
    ParameterServer():
						mGroupDefPub("group_def", &mGroupDefMsg),
						mParamDefPub("param_def", &mParamDefMsg),
						mGetDefSub("get_def", &ParameterServer::onGetDefReceived, this),
						mSetParamSrv("set_param", &ParameterServer::onHandleSetParam, this)
		{
		}

    void onGetDefReceived(tiny_reconfigure::GetDef const& msg);

    void onHandleSetParam(const tiny_reconfigure::SetParamRequest& req, tiny_reconfigure::SetParamResponse& res);
};


} /* namespace utl */

#endif /* UTL_PARAMETERSERVER_H_ */
