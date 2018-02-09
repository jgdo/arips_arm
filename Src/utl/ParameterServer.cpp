/*
 * ParameterServer.cpp
 *
 *  Created on: Feb 4, 2018
 *      Author: jgdo
 */

#include <utl/ParameterServer.h>

using namespace tiny_reconfigure;

namespace utl {

Parameter::Parameter(const char* name, ParameterGroup* group):
		mName(name)
{
	group->registerParameter(this);
}

ParameterGroup::ParameterGroup(const char* name):
		mName(name)
{
	ParameterServer::registerParameterGroup(this);
}

void ParameterGroup::registerParameter(Parameter* param) {
	mNumParams++;
	
	param->mNextParam = nullptr; // just to be sure
	
	if(mLastParameter) {
		mLastParameter->mNextParam = param;
	}
	mLastParameter = param;
	
	if(!mFirstParameter) {
		mFirstParameter = param;
	}
}

void ParameterServer::registerParameterGroup(ParameterGroup* group) {
	sNumGroups++;
	
	group->mNextGroup = nullptr; // just to be sure
	
	if(sAllGroupsLast) {
		sAllGroupsLast->mNextGroup = group;
	}
	sAllGroupsLast = group;
	
	if(!sAllGroupsFirst) {
		sAllGroupsFirst = group;
	}
}

ParameterServer ParameterServer::sTheParameterServer;

ParameterGroup* ParameterServer::sAllGroupsFirst = nullptr;
ParameterGroup* ParameterServer::sAllGroupsLast = nullptr;
GroupDef::_num_groups_type ParameterServer::sNumGroups = 0;

void ParameterServer::onGetDefReceived(const tiny_reconfigure::GetDef& msg) {
	if(msg.cmd == GetDef::CMD_LIST_ALL) {
		GetDef::_group_id_type groupId = 0;
		for(auto group = sAllGroupsFirst; group != nullptr; group = group->mNextGroup, groupId++) {
			mGroupDefMsg.group_id = groupId;
			mGroupDefMsg.group_name = group->mName;
			mGroupDefMsg.num_groups = sNumGroups;
			
			mGroupDefPub.publish(&mGroupDefMsg);
			
			GetDef::_param_id_type paramId = 0;
			for(auto param = group->mFirstParameter; param != nullptr; param = param->mNextParam, paramId++) {
				mParamDefMsg.group_id = groupId;
				mParamDefMsg.param_id = paramId;
				mParamDefMsg.num_params = group->mNumParams;
				mParamDefMsg.param_name = param->mName;
				mParamDefMsg.type = param->getType();
				param->fillValue(&mParamDefMsg.value_int, &mParamDefMsg.value_float);
				
				mParamDefPub.publish(&mParamDefMsg);
			}
		}
	} else if(msg.cmd == GetDef::CMD_GET_GROUP_DEF) {
		GetDef::_group_id_type groupId = 0;
		for(auto group = sAllGroupsFirst; group != nullptr; group = group->mNextGroup, groupId++) {
			if(groupId == msg.group_id) {
				mGroupDefMsg.group_id = groupId;
				mGroupDefMsg.group_name = group->mName;
				mGroupDefMsg.num_groups = sNumGroups;
				
				mGroupDefPub.publish(&mGroupDefMsg);
							
				GetDef::_param_id_type paramId = 0;
				for(auto param = group->mFirstParameter; param != nullptr; param = param->mNextParam, paramId++) {
					mParamDefMsg.group_id = groupId;
					mParamDefMsg.param_id = paramId;
					mParamDefMsg.num_params = group->mNumParams;
					mParamDefMsg.param_name = param->mName;
					mParamDefMsg.type = param->getType();
					param->fillValue(&mParamDefMsg.value_int, &mParamDefMsg.value_float);
					
					mParamDefPub.publish(&mParamDefMsg);
				}
				
				break;
			}
		}
	} else if(msg.cmd == GetDef::CMD_GET_PARAM_DEF) {
		GetDef::_group_id_type groupId = 0;
		for(auto group = sAllGroupsFirst; group != nullptr; group = group->mNextGroup, groupId++) {
			if(groupId == msg.group_id) {
				GetDef::_param_id_type paramId = 0;
				for(auto param = group->mFirstParameter; param != nullptr; param = param->mNextParam, paramId++) {
					if(paramId == msg.param_id) {
						mParamDefMsg.group_id = groupId;
						mParamDefMsg.param_id = paramId;
						mParamDefMsg.num_params = group->mNumParams;
						mParamDefMsg.param_name = param->mName;
						mParamDefMsg.type = param->getType();
						param->fillValue(&mParamDefMsg.value_int, &mParamDefMsg.value_float);
						
						mParamDefPub.publish(&mParamDefMsg);
						
						break;
					}
				}
				
				break;
			}
		}
	} // else TODO
}

void ParameterServer::onHandleSetParam(const tiny_reconfigure::SetParamRequest& req,
		tiny_reconfigure::SetParamResponse& res) {
	GetDef::_group_id_type groupId = 0;
	for(auto group = sAllGroupsFirst; group != nullptr; group = group->mNextGroup, groupId++) {
		if(groupId == req.group_id) {
			GetDef::_param_id_type paramId = 0;
			for(auto param = group->mFirstParameter; param != nullptr; param = param->mNextParam, paramId++) {
				if(paramId == req.param_id) {
					param->setValue(req.value_int, req.value_float);
					param->fillValue(&res.value_int, &res.value_float);
					res.result = 0;
					break;
				}
			}
			
			break;
		}
	}
}

} /* namespace utl */

