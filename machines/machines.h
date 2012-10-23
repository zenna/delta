/* Machines */
#include <list>
#include <map>
#include <string>

#include "sigma/primitives/values.h"

namespace sg {

class socket {

};

// Parent machine class
class machine {
private:
	// std::list<sg::Policy> policys;
	std::map<sg::Name, sg::socket> sockets;
	sg::Name my_name;
	sg::Type type;
public:
	machine(sg::Name name) : my_name(name) {}

	// Sets the intrinsic value of a socket
	void set_socket(sg::Name socket_name, Value* value) {
		// check machine has a socket of that name
		// check that machine is a value socket
		// set its value
	}
};

// This is a machine which takes an initial
// condition and runs only forward in time
class ensemble : public machine {
public:
	ensemble(sg::Name name) : machine(name) {}
	ensemble(std::string name) : machine(sg::Name(name)) {}
};

// The uncertain values
// Has only two sockets, data and directory
template <typename T>
class data : public machine {
public:
	data(sg::Name name) : machine(name) {}
	data(std::string name) : machine(sg::Name(name)) {}
};


}