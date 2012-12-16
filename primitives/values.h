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

class List : public Value {
public:
	std::list<sg::Value *> data;
	List(std::list<Value *> list_of_values) : data(list_of_values) {}
};

}
