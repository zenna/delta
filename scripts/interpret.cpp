/* This file will eventually be the interpreter for sigma machines */
#include "sigma/machines/machines.h"

// void run_universe(sg::ensemble &machine) {
// 	while (true) {
// 		machine.do_step();
// 	}
// }

/*
Modifies the directory of a source machine to propagate one of the machines sockets to another
*/
// void propagate(sg::machine source, sg::name socket_name, target_socket, double weight) {
// 	// 1. Check source has directory
// 	// 2. Check target socket exists
// 	// 3. Check existing entry
// 	// 4. Modify directory of source
// }

int main() {
	// Create an ensemble machine
	// Q: What are the initial sockets?
	// sg::ensemble loop("loop"); 

	sg::Type integer_type;
	integer_type.add_subtype(sg::Type::Prim::Integer);

	// Create all machines to go inside this ensemble
	sg::data one(sg::Name("one"), integer_type);
	int one_on_stack = 4;

	sg::Value one_value(one_on_stack, integer_type);
	one.set_socket(sg::Name("value"), one_value);

	// Q. Where to keep all these values stored?
	// Q. I need some kind of value constructor
	// Q. Tests
	// Q. Dealing with unbounded values
	// -TODO propoagation function

	// sg::data<int> zero(sg::Name("zero"));
	// sg::data<int> plus(sg::Name("plus"));

	// // Setup propagations
	// propagate(one, "value", plus, "arg0", 1.0);
	// propagate(two, "value", plus, "arg0", 1.0);
	// propagate(one, "machine", plus, "arg0", 1.0);

	// // Add the machines to the socket of ensemble. FIXME: reduce following two lines to one line using c++11
	// std::list<sg::machine *> loop_machines = {&one,&zero,&plus};
	// sg::List<sg::machine *> the_machines(loop_machines);
	// loop.set_socket(sg::Name("machines"), &the_machines);
	// propagate("one:machine", "two:love", 1.0)

	// run_universe(loop);
}