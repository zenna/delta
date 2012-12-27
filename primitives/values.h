#pragma once
#include <string>
#include "sigma/primitives/types.h"

namespace sg {

/*
Values need to store the actual value in memory
This is achieved using void pointers

*/
class Value {
public:

    void * value;
    sg::Type type;

    Value() {}

    template <typename T>
    Value(T data, sg::Type type) : type(type) {
        T* data_ptr = new T;
        *data_ptr = data;
        value = data_ptr;
    }

    // // Now what? 
    // sg::Type get_type() const {

    // }
};

class Tuple : public Value {
private:
    std::list<sg::Value *> data;
public:
    template <typename V>
    void push_value(V value) {
        sg::Value * value_ptr = new sg::Value;
        *value_ptr = value;
        data.push_back(value_ptr);
    }

    // sg::Type get_type() const {
    //     // Go through each member of value and of data
    //     // Cast it onto whatever type its supposed to be
    //     // Then call get_type
    // }
};

class List : public Value {
private:
    std::list<sg::Value *> elements;
public:
    template <typename V>
    void push_value(V value) {
        sg::Value * value_ptr = new sg::Value;
        *value_ptr = value;
        elements.push_back(value_ptr);
    }


    // POSTPONING TYPE CHECKING
    // sg::Type get_type() const {
    //     for (sg::Value : elements) {
    //         elements
    //     }
    //     // Go through each member of value and of data and get shit done
    // }
};

}