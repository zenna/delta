#pragma once

/* Primitive Socket Types */
#include <string>
#include "sigma/primitives/types.h"

namespace sg {

class Value {
	void * value;
	sg::Type type;

public:
	template <typename T>
	Value(T &data, sg::Type type) : type(type) {
		value = &value;
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
