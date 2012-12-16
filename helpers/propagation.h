#pragma once

namespace sg {

// Does the machine have a value socket of a particular name
bool has_machine_value_socket(sg::Machine const &machine, sg::Name socket_name) {

}

// This function will modify the directory value_socket of a machine
// To cause it to propagate to another socket
void propagate(sg::Machine &source, sg::Name socket_name, target_socket, double weight) {
	bool source_has_value_directory = has_machine_value_socket(source, sg::Name("directory")); 
	// 1. Check source has directory
	// 2. Check target socket exists
	// 3. Check existing entry
	// 4. Modify directory of source
}

// void run_universe(sg::ensemble &machine) {
// 	while (true) {
// 		machine.do_step();
// 	}
// }


}