/* Primitive Socket Types */
#include <string>
#include "sigma/primitives/types.h"

namespace sg {

class Value {

};

/* This is an identifier for any machine or socket */
class Name {
public:
	std::string data;
	Name(std::string name) : data(name) {};
};

template <typename T>
class List : public Value {
public:
	sg::Type ListType;
	std::list<T> data;
	List(std::list<T> list_of_values) : data(list_of_values) {}
};

}
