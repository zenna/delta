/*input output*/
#pragma once
#include <iostream>
// #include "sigma/machines/machines.h"

namespace sg {

// Print a socket
// FIXME, now only prints ints
template<typename T>
void print_value_socket(T &value_socket) {
	int * value = static_cast<int*>(value_socket.value.value);
	std::cout << *value << std::endl;
}

}