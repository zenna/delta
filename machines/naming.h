#pragma once

/* Naming */
namespace sg {

/* This is an identifier for any machine or socket */
class Name {
public:
	std::string data;
	Name(std::string name) : data(name) {};
};

}