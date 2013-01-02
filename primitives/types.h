#pragma once

/* Primitive Socket Types */
#include "sigma/machines/naming.h"

namespace sg {
/*
The type of a machine specifies:
The number and names of value and variable sockets it posseses.
For each socket, the type of values it contains, where the type could be a primitive type
e.g. Int, Node, Float.  Or it could be a compound type such as a list or a tuple.  Or it could be a
type variable.
Type variables are used for polymorphic machines, i.e. a single addition machine which can add both floats
and integers.

t ->
    socket_expr
	| socket_expr * socket_expr
	| socket_expr + socket_expr

socket_expr -> quantity : s_type

quantity ->
	| [0-9]* #any number
	| unbounded name
	| unbounded

name ->
	| name-anyword

socket_type	->
	Integer
	| Node
	| Float
	| String
	| Bool
	| [socket_type]
	| (t_p)

t_p ->
	T
	| socket_type, socket_type

The operations we will need to use hte type for
1. To check if there are any other nodes of a comptable type
2. For set_socket. a machine dynamically creates sockets according to its type
*/

// Need a datastructure which makes it fast to test equivalence
// And can test to see if a type variable is consistent
class Type {
public:
	enum class Prim {
	    Integer,
	    Float,
	    Double,
	    String,
	    Bool,
	    Node,
	    Name,
	    Tuple,
	    List
	};

	std::list<Prim> subtypes;
	std::map<int, int> edges;

	Type() {}

	Type(Prim primitive) {
		subtypes.push_back(primitive);
	}

	void add_subtype(Prim primitive) {
		subtypes.push_back(primitive);
	}
	void add_edge(int, int) {}

	bool operator == (const sg::Type &other) const {
		return (subtypes == other.subtypes && edges == other.edges);
	}
};


class SocketType {
public:
	sg::Name name;
	int quantity;
	sg::Type type;
	SocketType(sg::Name name, int quantity, sg::Type type) : name(name), quantity(quantity), type(type) {}
};

// A machine type is just a list of socket types
class MachineType {
public:
	std::list<sg::SocketType> socket_types;
	void add_socket_type(sg::SocketType socket_type) {
		socket_types.push_back(socket_type);
	}
};

}
