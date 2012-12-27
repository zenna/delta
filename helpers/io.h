/*input output*/
#pragma once
#include <iostream>
// #include "sigma/machines/machines.h"

namespace sg {

// Print a socket
// FIXME, now only prints ints
template<typename T>
void print_value_socket(T value_socket) {
	int * value = static_cast<int*>(value_socket.value.value);
	std::cout << *value << std::endl;
}

//Since variadic templates are recursive, must have a base case
void output() { std::cout << '\n'; }

//Output function to output any type without type specifiers like printf() family
template <typename T, typename ...P>
void output(T t, P ...p)
{
  std::cout << t << ' ';
  if (sizeof...(p)) { output(p...); }
  else { std::cout << '\n'; }
}

}