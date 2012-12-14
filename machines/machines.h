#pragma once
/* Machines */
#include <list>
#include <map>
#include <string>
#include <iostream>

#include "sigma/machines/naming.h"
#include "sigma/primitives/values.h"
#include "sigma/primitives/types.h"
#include "sigma/helpers/io.h"



namespace sg {

class ValueSocket {
public:
	sg::Value value;
	void set_value(sg::Value value_) {
		value = value_;
	}
};

/* Parent machine class
There are a set of primitive machines.
Each primitve has a socket structure
for instance a plus socket might have two inputs, a directory and one output.
*/
class machine {
public:
	// std::list<sg::Policy> policys;
	std::map<sg::Name, sg::ValueSocket> value_sockets;
	// std::map<sg::Name, sg::ValueSocket> variable_sockets;
	sg::Name name;
	sg::MachineType machine_type;
	machine(sg::Name name) : name(name) {}

	sg::ValueSocket get_value_socket(sg::Name socket_name) {
		auto value = value_sockets.find(socket_name);
		if (value == value_sockets.end()) {
			std::cout << "Couldn't find value" << std::endl;
		}
		// std::cout << "Socket name being to is " << value->right << std::endl;
		return value_sockets[socket_name];
	}

	// Sets the intrinsic value of a socket
	// TODO: Checks for already set sockets
	void set_socket(sg::Name socket_name, Value value) {

		// check machine has a value socket of that name -
		for (auto &socket_type : machine_type.socket_types) {
			if (socket_type.name == socket_name) {
				// Check type signatures match
				if (socket_type.type == value.type) {
					value_sockets[socket_name].set_value(value);
					std::cout << "RIGHT TYPE";
				}
				else {
					std::cout << "WRONG TYPE";
				}
			}
		}
		sg::print_value_socket(value_sockets[socket_name]);
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
	data(sg::Name name, sg::Type value_type) : machine(name) {
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
		sg::SocketType value(sg::Name("value"), 1, value_type);
		machine_type.add_socket_type(directory);
		machine_type.add_socket_type(value);
	}
};

}