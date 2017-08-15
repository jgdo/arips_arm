/*
 * ParameterStore.h
 *
 *  Created on: Aug 12, 2017
 *      Author: jgdo
 */

#ifndef UTL_PARAMETERSTORE_H_
#define UTL_PARAMETERSTORE_H_

#include <string>
#include <array>

namespace utl {

template<class T>
class ParameterEntryImpl;

class ParameterEntry {
public:
	virtual ~ParameterEntry() {
	}
	
	template<class T>
	T get() const;

	template<class T, class V>
	T set(V&& v) const;

	virtual int setFromString(const char* str) = 0;
};

template<class T>
class ParameterEntryImpl: public ParameterEntry {
public:
	T value;

	ParameterEntryImpl(T v = T()) :
			value(v) {
	}
	
	virtual ~ParameterEntryImpl() {
	}
	
	T getValue() const {
		return value;
	}
	
	template<class V>
	void setValue(V&& v) {
		value = v;
	}
	
	virtual int setFromString(const char* str) override {
		value = std::atof(str); // todo
		return 0;
	}
};

template<class T>
T ParameterEntry::get() const {
	const ParameterEntryImpl<T>* impl = static_cast<const ParameterEntryImpl<T>*>(this);
	if (impl)
		return impl->getValue();
	else
		return T();
}

template<class T, class V>
T ParameterEntry::set(V&& v) const {
	ParameterEntryImpl<T>* impl = static_cast<ParameterEntryImpl<T>*>(this);
	if (impl)
		impl->setValue(v);
}

enum ParameterStoreEntryID {
	PS_ID_PID_P, PS_ID_PID_I, PS_ID_PID_D, PS_ID_SETPOINT, PS_ID_END
};

class ParameterStore {
public:
	template<class T>
	static T get(ParameterStoreEntryID id) {
		return storeEntries().at(id)->get<T>();
	}
	
	template<class T>
	static T* getPtr(ParameterStoreEntryID id) {
		ParameterEntryImpl<T>* impl = static_cast<ParameterEntryImpl<T>*>(&storeEntries().at(id));
		if (impl)
			return &impl->value;
		else
			return nullptr;
	}
	
	template<class T, class V>
	static void set(ParameterStoreEntryID id, V&& value) {
		return storeEntries().at(id)->set<T, V>(value);
	}
	
	static inline int setFromString(ParameterStoreEntryID id, const char* str) {
		if (id >= storeEntries().size())
			return 1;
		return storeEntries().at(id)->setFromString(str);
		
	}
	
private:
	static std::array<ParameterEntry*, PS_ID_END>& storeEntries();
	
};

} /* namespace utl */

#endif /* UTL_PARAMETERSTORE_H_ */
