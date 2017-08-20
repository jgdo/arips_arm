/*
 * String.h
 *
 *  Created on: Aug 20, 2017
 *      Author: jgdo
 */

#ifndef UTL_STRING_H_
#define UTL_STRING_H_

#include <cstddef>
#include <stdarg.h>

namespace utl {

template<size_t N>
class String {
	char buffer[N];

public:
	String() {
		buffer[0] = 0;
	}
	
	String(const char*str) {
		strncpy(buffer, str, N - 1);
		buffer[N - 1] = 0;
	}
	
	String(const char*fmt, ...) {
		va_list args;
		va_start(args, fmt);
		vsnprintf(buffer, N, fmt, args);
		va_end(args);
	}
	
	const char* data() const {
		return buffer;
	}
	
};

}

#endif /* UTL_STRING_H_ */
