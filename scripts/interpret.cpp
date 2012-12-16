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

// TODO
1. Functional machines
2. remove uninitialised value sockets
3. Do sample based propagation
4. 
*/

int main() {
	// You could imagine all the people,

	// Type values
	sg::Type integer_type(sg::Type::Prim::Integer);

	sg::Type name_type(sg::Type::Prim::Name);

	sg::Type double_type(sg::Type::Prim::Double);

	// Create all machines to go inside this ensemble
	sg::Data one(sg::Name("one"), integer_type);
	sg::Value one_value(1,integer_type);
	one.set_socket(sg::Name("value"), one_value);

	sg::Data zero(sg::Name("zero"), integer_type);
	sg::Value zero_value(0,integer_type);
	zero.set_socket(sg::Name("value"), one_value);

	// Let's create the data for a directory
	setup_coupling(one);

	// 
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