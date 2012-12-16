/* This file will eventually be the interpreter for sigma machines */
#include "sigma/machines/machines.h"
#include "sigma/helpers/io.h"


/*
// Q. Where to keep all these values stored?
Value, value socket, ensemble, just some big 

// Q. I need some kind of value constructor
// Q. Tests
// Q. Dealing with unbounded values

// -TODO propoagation function
*/

int main() {
	// You could imagine all the people,

	// Create an ensemble machine
	// Q: What are the initial sockets?
	// sg::ensemble loop("loop");

	sg::Type integer_type;
	integer_type.add_subtype(sg::Type::Prim::Integer);

	// Create all machines to go inside this ensemble
	sg::Data one(sg::Name("one"), integer_type);
	int one_on_stack = 1;
	sg::Value one_value(1,integer_type);
	one.set_socket(sg::Name("value"), one_value);
	print_value_socket(one.get_value_socket(sg::Name("value")));

	// // Create all machines to go inside this ensemble
	// sg::Data zero(sg::Name("zero"), integer_type);
	// int zero_on_stack = 0;

	// sg::Value zero_value(zero_on_stack, integer_type);
	// zero.set_socket(sg::Name("value"), zero_value);

	// TODO: Set the directories of these machiens
	// Add a functional machine
	// sg::integerAdd add(sg::Name("add"));

	// RUN!!!

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