/*input output*/
#pragma once
#include <iostream>

namespace sg {

// Print a socket
// FIXME, now only prints ints
void print_value_socket(sg::ValueSocket value_socket) {
	int * value = static_cast<int*>(value_socket.value.value);
	std::cout << *value << std::endl;
}

}