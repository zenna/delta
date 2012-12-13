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

};

class SocketType {
	sg::Name socket_name;
	int number;
	sg::Type type;
};

class MachineType {
	std::list<sg::SocketType> socket_types;
};

class ListType : Type {
	sg::Type element_type;
	ListType(sg::Type element_type) : element_type(element_type) {}
};

class BasicType : Type {
	enum class prim {
	    Integer,
	    Float,
	    String,
	    Bool,
	    Node
	};
	prim primitive_type;
};

// class VariableType : Type {
// 	int index;
// };

// class TupleType : Type {
// 	std::list<sg::type> self;
// };

}
