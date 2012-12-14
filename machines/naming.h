#pragma once
#include <iostream>

/* Naming */
namespace sg {

/* This is an identifier for any machine or socket */
class Name {
public:
	std::string data;
	Name(std::string name) : data(name) {};

	bool operator== (const sg::Name &other) const {
		return (data == other.data);
	}

	bool operator< (const sg::Name &other) const {
		// FIXME
		return true;
	}

	std::ostream & operator<< (std::ostream &out) {
		out << data;
		return out;
	}
};

}