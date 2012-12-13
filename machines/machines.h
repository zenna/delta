#pragma once
/* Machines */
#include <list>
#include <map>
#include <string>

#include "sigma/machines/naming.h"
#include "sigma/primitives/values.h"
#include "sigma/primitives/types.h"


namespace sg {

class ValueSocket {
public:
	sg::Value value;
	void set_value(sg::Value value) {
		value = value;
	}
};

/* Parent machine class
There are a set of primitive machines.
Each primitve has a socket structure
for instance a plus socket might have two inputs, a directory and one output.
*/
class machine {
private:
	// std::list<sg::Policy> policys;
	std::map<sg::Name, sg::ValueSocket> value_sockets;
	// std::map<sg::Name, sg::ValueSocket> variable_sockets;
	sg::Name name;
	sg::Type type;
public:
	machine(sg::Name name) : name(name) {}

	// Sets the intrinsic value of a socket
	void set_socket(sg::Name socket_name, Value value) {
		// check machine has a value socket of that name - check type signature
		if (socket_in_type(socket_name)) {
			// TODO: Check type is same
			value_sockets[socket_name].set_value(value);
		}
	}

	// TODO: Implement
	bool socket_in_type(sg::Name socket_name) {
		return true;
	}

	// Checks whether a socket has been initialised
	bool is_value_socket_init(sg::Name socket_name) {
		// Check if it exists in 
		return true;//(value_sockets.find(socket_name) != value_sockets.end());
	}
};


// // So perhaps I should be able to specify in the constructor, which are values and which are variables
// class ensemble : public machine {
// public:
// 	// t = 	1 value 'd' : Directory +
// 	//		unbounded value 'machine' : Node + 
// 	sg::Type type; 
// 	ensemble(sg::Name name, std::list<sg::>) : machine(name) {
// 		sg::Type ensemble_type;
// 		ensemble_type.push_back();
// 	}
// };

// The uncertain values
// Has only two sockets, data and directory
class data : public machine {
public:
	// t = 	1 value 'd' : Directory +
	//		unbounded value 'value' : T 
	data(sg::Name name) : machine(name) {
		sg::MachineType machine_type;
		sg::Type type;
		type.add_subtype(sg::Type::Prim::Tuple);
		type.add_subtype(sg::Type::Prim::List);
		type.add_subtype(sg::Type::Prim::Name);
		type.add_subtype(sg::Type::Prim::Name);
		type.add_subtype(sg::Type::Prim::Float);
		type.add_edge(0,1);
		type.add_edge(1,2);
		type.add_edge(1,3);
		type.add_edge(1,4);

		// A tuple is [(name,name,weight)]
		sg::SocketType directory(sg::Name("directory"), 1, type);
		machine_type.add_socket_type(directory);
	}
};

}