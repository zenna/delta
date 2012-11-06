/* This file will eventually be the interpreter for sigma machines */
#include "sigma/machines/machines.h"

void run_universe(sg::forward_ensemble &machine) {
	while (true) {
		machine.do_step();
	}
}

// OK so here's the problem.
/* We are saying the policy has the capacity to transform and modify values at will
// The problem then is how does this interact with a;; otehr evidence.

I have a chicken and egg problem with the directories unless I let directories be value ndoes.
But I am forgetting all about conditioning.  Goddamit!
How am I?

I am saying I can edit values of nodes as we speak.

In order to do any kind of propagation I will need to either:
1. make directories values
THe problem with directories as values is that once set I'll never be able to get rid of them.
But maybe that's ok because I can just propagate from a 	
2. preload variables

*/



void propagate(source_socket, target_socket, double weight) {
	// Check if it has a directory value node
}

int main() {
	// Choose an ensemble, must be one already present or implicit main
	// Place a copy of a primtive
	sg::ensemble loop;
	sg::ensemble evidence;

	//Q. shoud data and value nodes be different,
	sg::data<int> one("one");
	sg::data<int> zero("zero");
	sg::plus<int> plus("plus");

	// Add the machines to the socket
	sg::list<sg::machine> machines(one,zero,plus);
	loop.set_socket("machines", machines);
	propagate("one:machine", "loop:program", 1.0);
	propagate("zero:machine", "loop:program", 1.0);
	propagate("plus:machine", "loop:program", 1.0);

	// Create the evidence formulae	
	sg::data<int> one_val("one");
	sg::equal equal("equal?");

	// Create a relation for the directory socket
	// Add an entry which propagates its data to the 0th arg of plus on alpha channel
	sg::tuple<sg::name, sg::name, sg::real> d("self:data", "equals?:0", 1.0);
	sg::list<sg::tuple> relation(d);
	one_val.set_socket("dir",d);

	// Create a relation for the directory socket
	// Add an entry which propagates its data to the 0th arg of plus on alpha channel
	sg::tuple<sg::name, sg::name, sg::real> d("self:data", "equals?:1", 1.0);
	sg::list<sg::tuple> relation(d);
	one.set_socket("dir",d);

	// Create the evidence ensemble
	evidence.add_machines(one_val,one,equal);

	// Propagate evidence to loop
	sg::tuple<sg::name, sg::name, sg::real> d("self:machine", "loop:1", 1.0);
	sg::list<sg::tuple> relation(d);
	evidence.set_socket("dir",d);

	// Ok so what is going to make this thing run
	run_universe(loop);
}