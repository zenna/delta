/* This file will eventually be the interpreter for sigma machines */
#include "sigma/machines/machines.h"
#include "sigma/helpers/io.h"

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

    sg::integerAdd add(sg::Name("add"));

    // Let's create the data for a directory
    setup_coupling(one, sg::Name("value"), add, sg::Name("arg0"), 1.0);

    // TODO: Set the directories of these machiens
    // Add a functional machine
    // sg::integerAdd add(sg::Name("add"));

    // run_universe(loop);
}