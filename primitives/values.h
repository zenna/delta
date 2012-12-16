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
	Value(T data, sg::Type type) : type(type) {
		T* data_ptr = new T;
		*data_ptr = data;
		value = data_ptr;
	}
};

class Tuple : public Value {
	template <typename T>
	Value(T data, sg::Type type) : type(type) {
		T* data_ptr = new T;
		*data_ptr = data;
		value = data_ptr;
	}
};

class List : public Value {
public:
	std::list<sg::Value *> data;
	List(std::list<Value *> list_of_values) : data(list_of_values) {}
};

}
