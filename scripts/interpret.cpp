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

	// Create all machines to go inside this ensemble
	sg::data<int> one(sg::Name("one"));
	int one_on_stack = 1;
	sg::Value one_value(one_on_stack);
	one.set_socket(sg::Name("value"), one_value);

	// Make value polymorphic, or have void pointers

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