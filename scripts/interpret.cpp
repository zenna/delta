/* This file will eventually be the interpreter for sigma machines */
#include <random>
#include "sigma/machines/machines.h"
#include "sigma/helpers/io.h"
#include "sigma/helpers/propagation.h"

int main() {
    sg::Type integer_type(sg::Type::Prim::Integer);

    sg::Type name_type(sg::Type::Prim::Name);

    sg::Type double_type(sg::Type::Prim::Double);

    // Create all machines to go inside this ensemble
    sg::Data one(sg::Name("one"), integer_type);
    sg::Value one_value(1,integer_type);
    one.set_socket(sg::Name("value"), one_value);

    sg::Data zero(sg::Name("zero"), integer_type);
    sg::Value zero_value(0,integer_type);
    zero.set_socket(sg::Name("value"), one_value);

    sg::IntegerAdd add(sg::Name("add"));

    // Let's create the data for a directory
    sg::setup_coupling(one, sg::Name("value"), add, sg::Name("arg0"), 1.0);

    // Run the system - i.e. execute the program
    std::mt19937 prng_engine; prng_engine;
    int num_samples = 10, time_steps = 10;
    std::list<sg::Machine *> ensemble = {&one, &zero, &add};
    sg::propagate_samples(num_samples, prng_engine, time_steps)
}