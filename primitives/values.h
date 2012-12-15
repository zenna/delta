#pragma once

/* Primitive Socket Types */
#include <string>
#include "sigma/primitives/types.h"

namespace sg {

class Value {
public:

	void * value;
	sg::Type type;

	Value() {}

	template <typename T>
	Value(T &data, sg::Type type) : type(type) {
		value = &data;
	}
};

template <typename T>
class List : public Value {
public:
	sg::Type ListType;
	std::list<T> data;
	List(std::list<T> list_of_values) : data(list_of_values) {}
};

}
