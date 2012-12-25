#pragma once
#include <vector>
#include <pair>

namespace sg {

sg::Type make_directory_type() {
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

// Does the machine have a value socket of a particular name
bool has_machine_value_socket(sg::Machine const &machine, sg::Name socket_name) {

}

// This function will modify the directory value_socket of a machine
// To cause it to propagate to another socket
void setup_coupling(sg::Machine &source, sg::Name socket_name,
                sg::Name target_machine, target_socket, double weight) {
    // Sanity: check directory and dst socket exist
    bool source_has_value_directory = has_machine_value_socket(source, sg::Name("directory")); 
    bool target_has_socket = has_machine_value_socket(target, target_socket);
    if (source_has_value_directory && target_socket) {
        src_socket = src_machine.get_socket(socket_name);
        dst_socket = dst_machine.get_socket(socket_name);
        
        // If types match, modify create value
        if (type_consistent(src_socket, dst_socket)) {
            sg::Value source_name(sg::Name("one"), name_type);
            sg::Value target_name(sg::Name("zero"), name_type);
            sg::Value weight(1.0, double_type);
            std::list<Value *> dir_entry_list = {source_name, target_name, weight};
            sg::Tuple dir_entry(dir_entry_list, sg::Type(sg::Type::Prim::Tuple));
            src_socket.set_socket();
        }
    }
}

/**
 @brief  Do sample based propagation for list of machines
 @tparam PRNG                       PRNG engine
 @param[in]  num_samples            num samples each socket takes
 @param[in]  prng_engine            PRNG engine - stores state of RNG, e.g. std::mt19937
 @param[in]  time_steps        Number of timesteps to execute
 */
template <typename PRNG>
void propagate_samples(std::list<sg::Machine*> machines, int num_samples,
                PRNG &prng_engine, int time_steps) {
    // For every socket, store those that projected to me in the
    // the previous timestep.
    std::vector<std::pair<std::vector<sg::socket*>, std::vector<double>> projecting_to_me;
    
    for (int i = 0; i<time_steps; ++i) {
        // 1. for each socket draw num_samples and store in current_samples
        for (int j = 0; j< projecting_to_me.length(); ++j) {
            auto &incident_sockets = projecting_to_me[j];
            // 1. Now sample n times
            for (int k = 0; k<num_samples; ++k) {
                int sampled_socket_id = weighted_sample(incident_sockets.second, prng_engine);
                sg::socket sampled_socket = incident_sockets.first[sampled_socket];
                int sampled_value_id = uniform_list_sample(sampled_socket->prev_samples);
                current_samples.push_back();
            }
        }
        for (auto machine : machines) {
            // 2. Execute policy for samples
        }

        projecting_to_me.clear();
        for (auto machine : machines) {
            // Do propagation: i.e. build projecting to me,

            
        }
    }
}

}   