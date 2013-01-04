#pragma once
/* Machines */
#include <list>
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "sigma/machines/naming.h"
#include "sigma/primitives/values.h"
#include "sigma/primitives/types.h"
#include "sigma/helpers/io.h"
#include "sigma/helpers/invalid.h"


namespace sg {

sg::Type make_dir_type() {
    sg::Type dir_type;
    dir_type.add_subtype(sg::Type::Prim::Tuple);
    dir_type.add_subtype(sg::Type::Prim::List);
    dir_type.add_subtype(sg::Type::Prim::Name);
    dir_type.add_subtype(sg::Type::Prim::Name);
    dir_type.add_subtype(sg::Type::Prim::Float);
    dir_type.add_edge(0,1);
    dir_type.add_edge(1,2);
    dir_type.add_edge(1,3);
    dir_type.add_edge(1,4);
    return dir_type;
}

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


/**
 @brief  Base Machine Class

 There are a set of primitive machines.
 Each primitve has a socket structure
 for instance a plus socket might have two inputs, a directory and one output.
 */
class Machine {
public:
    // A machine is tuple (S_v, S_var, X, T, Pi)
    // std::list<sg::Policy> policys;
    std::map<sg::Name, sg::VariableSocket> variable_sockets;
    sg::Name name;
    sg::MachineType machine_type;
    Machine(sg::Name name) : name(name) {}


    // Return a socket by its name
    sg::VariableSocket & get_socket(sg::Name socket_name) const {
        auto socket = variable_sockets.find(socket_name);
        if (socket == variable_sockets.end()) {
            std::cout << "Couldn't find value" << std::endl;
            return sg::INVALID_SOCKET;
        }
        else {
            return socket->second;
        }
    }

    /**
     @brief  Sets the intrinsic value of a socket
     */
    void set_socket(sg::Name socket_name, Value value) {
        // TODO Checks for already set sockets

        // check machine has a value socket of that name -
        for (auto &socket_type : machine_type.socket_types) {
            if (socket_type.name == socket_name) {
                // Check type signatures match
                if (socket_type.type == value.type) {
                    variable_sockets[socket_name].set_value(value);
                    std::cout << "Right Type";
                }
                else { 
                    std::cout << "WRONG TYPE";
                }
            }
        }
    }

    // executes the policy, i.e. performs a single timestep
    // void execute_policy() = 0;
};


// // So perhaps I should be able to specify in the constructor, which are values and which are variables
// class ensemble : public machine {
// public:
//  // t =  1 value 'd' : Directory +
//  //      unbounded value 'machine' : Node + 
//  sg::Type type; 
//  ensemble(sg::Name name, std::list<sg::>) : machine(name) {
//      sg::Type ensemble_type;
//      ensemble_type.push_back();
//  }
// };

// The uncertain values
// Has only two sockets, data and directory
class Data : public Machine {
public:
    // t =  1 value 'd' : Directory +
    //      unbounded value 'value' : T 
    Data(sg::Name name, sg::Type value_type) : Machine(name) {
        sg::Type dir_type = sg::make_dir_type();

        // A tuple is [(name,name,weight)]
        sg::SocketType directory(sg::Name("directory"), 1, dir_type);
        sg::SocketType value(sg::Name("value"), 1, value_type);
        machine_type.add_socket_type(directory);
        machine_type.add_socket_type(value);
    }
};

// The uncertain values
// Has only two sockets, data and directory
class IntegerAdd : public Machine {
public:
    // t =  1 value 'd' : Directory +
    //      unbounded value 'value' : T 
    IntegerAdd(sg::Name name) : Machine(name) {
        sg::Type dir_type = sg::make_dir_type();

        // A tuple is [(name,name,weight)]
        sg::SocketType directory(sg::Name("directory"), 1, dir_type);

        sg::Type integer_type;
        integer_type.add_subtype(sg::Type::Prim::Integer);
        sg::SocketType arg0(sg::Name("arg0"), 1, integer_type);
        sg::SocketType arg1(sg::Name("arg1"), 1, integer_type);
        sg::SocketType out0(sg::Name("out0"), 1, integer_type);

        machine_type.add_socket_type(directory);
        machine_type.add_socket_type(arg0);
        machine_type.add_socket_type(arg1);
        machine_type.add_socket_type(out0);
    }

    // Don't execute
    void execute_policy() {
        // a = variable_sockets[sg::Name("arg0")];
        // b = variable_sockets[sg::Name("arg1")];
        // o = int(a.value.value) + int(b.value.value); 
        // out = variable_sockets[sg::Name("out1")];
        // out.value = o;
    }
};

// This machine takes nodes into its sockets and performs sampe based propagation
// Proposal takes as input, Integer for num samplee, 
// Has one socket for a machine.

class SampleEnsemble : public Machine {
public:
    // The policy for execute machines looks at the list of machines in its socket
    // and transforms them.
    // This setups some conceptual issues, one we havee a modification of values in place.
    // Which is policy and things writing ot the same place
    // Got to get rid of that so ok the policy does two things it takes in nodes
    // and puts in another place, does modification in another node

    // And then for all the nodes in a second slot it does its updating from t to t+1


    // t =  1 value 'd' : Directory +
    //      unbounded value 'value' : T 
    SampleEnsemble(sg::Name name, sg::Type value_type) : Machine(name) {
        sg::Type dir_type = sg::make_dir_type();

        // A tuple is [(name,name,weight)]
        sg::SocketType directory(sg::Name("directory"), 1, dir_type);
        sg::SocketType value(sg::Name("value"), 1, value_type);
        machine_type.add_socket_type(directory);
        machine_type.add_socket_type(value);
    }
};


// class Policy {
// public:
//     // The actual function, must take asinput the number of points
//     // 
//     primitive_function(list<Values> inputs, list<Values> outputs)
//     std::map<int,sg::Name> mapping;
// };


}