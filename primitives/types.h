/* Primitive Socket Types */

namespace sg {

/* From a type system the basics we need are
the ability to constrain which sockets can 
propagate to other sockets.
Ideally we would like to type our programs.
What would it mean for two programs to be type consistent
Well it imposes some structural constraints on the program*/

// Need a datastructure which makes it fast to test equivalence
// And can test to see if a type variable is consistent
class Type {

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



// class Socket {
// 	sg::name name;
// 	sg::type type;
// 	Belief;
// 	Weight;
// };

}
