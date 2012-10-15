/* This file will eventually be the interpreter for sigma machines */
#include "sigma/machines/machines.h"

void run_universe(sg::forward_ensemble &machine) {
	while (true) {
		machine.do_step();
	}
}

int main() {
	sg::forward_ensemble loop;

	sg::data<int> one("one");
	sg::data<int> zero("zero");

	// Create a relation for the directory socket
	sg::dir_relation d;
	// Add an entry which propagates its data to the 0th arg of plus on alpha channel
	d.add_entry("self:data", "plus:0", 1.0, "alpha");
	// Add this relation to the socket, with value 1.0
	one.get_socket("dir").set_value(d,1.0);
	// Add a value to the data socket with value 1.0
	one.get_socket("data").set_value(1, 0.0); // FIXME, value should be a pointer

	// Do the same again for node zero.
	sg::dir_relation d2;
	d2.add_entry("self:data", "plus:1", 1.0, "alpha");
	zero.get_socket("dir").set_value(d2,1.0);
	zero.get_socket("data").set_value(0, 0.0); // FIXME, value should be a pointer	

	// Now for plus
	sg::func plus("plus");
	sg::dir_relation d3;
	d3.add_entry("self:sum", "zero:data", 1.0, "alpha");
	plus.get_socket("dir").set_value(d3,1.0);
	plus.get_socket("data").set_value(0, 0.0); // FIXME, value should be a pointer	

	// Should it be possible to just add data to a socket
	// Or must it be incident on it?
	// Yes yes it should be, unless I make a second kind of unvariable node.
	// if I make non variable nodesm it means sigma machines cant propagate anywhere,
	// well that's fine because they can't anyway, the important point is not that
	// they can propagate anywhere, it's they they dont have to negotiate with other propagators
	// These value nodes would be able to propagate.  But they wouldn't recieve input
	// and they wouldnt store beliefs

	// Now I am not sure what problem they solve, it means only that I wouldnt need to store
	// Values in machines, but then I am just storing them in another machine.   

	// When we go onto program induction tasks, how is a program going to embed its
	// nodes with values, right?
	// Well you might imagine some kind of ensemble which takes names and values and outputs another one with them embedded
	// The other problem with nodes storing values is how to revie beliefs.
	// I have a value saying I am 4 with weight 10.
	// I.e. there needs to be some weight associated with this belief if its reliability is to be compared with other evidence
	// Any intrinnstic belief will need to be weighted.
	loop.add(one,two,plus);

	// Do I want the node to update over time or just be quierable
	// Queryable, for propositions, we don't want to state of the ensemble to change over time
	// On the other hand there are cases when we don't want the thing to be a black box
	// Lets have two cases for this, and define a forward one as one which flows in time.

	// Ok so what is going to make this thing run
	run_universe(loop);
}