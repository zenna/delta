#pragma once

#include "sigma/primitives/values.h"

namespace sg {
	
// A variable socket can be propagated to and stores
// Samples from its distribution
class VariableSocket {
public:
    sg::Value value;
    std::vector<sg::Value> samples;
    std::vector<sg::Value> prev_samples;
    void set_value(sg::Value value_) {
        value = value_;
    }
};


}