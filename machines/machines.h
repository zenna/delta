/* Machines */
#include <list>

namespace sg {

/* From a type system the basics we need are
the ability to constrain which sockets can 
propagate to other sockets.
Ideally we would like to type our programs.
What would it mean for two programs to be type consistent
Well it imposes some structural constraints on the program*/
class type {

};

class Socket {
	sg::name name;
	Belief;
	Weight;
	sg::type type;
};

}

namespace sg {

typedef name int;

// Parent machine class
class machine {
private:
	std::list<Policy> policys;
	std::list<sg::Socket> sockets;
	sg::name name;
	sg::type type;

public:
	machine(sg::name name) {}

	// Sets the intrinsic value of a socket
	set_socket(sg::name socket_name, double weight, void* value) {

	}
};

// This is a machine which takes an initial
// condition and runs only forward in time
class forward_ensemble : public machine {

public:
	// Add a machine to this ensemble
	void add(sg::machine node) {

	}
};

// The uncertain values
// Has only two sockets, data and directory
class data : public sg::machine {

};


}