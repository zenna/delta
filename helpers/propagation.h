#pragma once
#include <vector>
#include <map>
#include "sigma/machines/machines.h"
#include "sigma/helpers/invalid.h"

namespace sg {


/**
 @brief  Check if machine has socket of given name
 */
bool has_machine_socket(sg::Machine const &machine, sg::Name socket_name) {
    if (is_invalid(machine.get_socket(socket_name))) {
        return false;
    }
    else {
        return true;
    }
}

/**
 @brief  Check if sockets are the same type
 */
bool same_type(sg::VariableSocket const &socket_1, sg::VariableSocket const &socket_2) {
    // TODO: Implement this
    return true;
}

/**
 @brief  Modify directory socket to propagate to another
 */
void setup_coupling(sg::Machine &src_machine, sg::Name src_socket_name,
                sg::Machine dst_machine, sg::Name dst_socket_name, double weight) {
    // Sanity: check directory and dst socket exist
    bool src_has_dir = has_machine_socket(src_machine, sg::Name("directory"));
    bool src_socket_exists = has_machine_socket(src_machine, src_socket_name);
    bool dst_socket_exists = has_machine_socket(dst_machine, dst_socket_name);

    if (src_has_dir && src_socket_exists && dst_socket_exists) {
        sg::VariableSocket src_socket = src_machine.get_socket(src_socket_name);
        sg::VariableSocket dst_socket = dst_machine.get_socket(dst_socket_name);
        
        // If types match, modify create value
        if (same_type(src_socket, dst_socket)) {
        	sg::Type name_type(sg::Type::Prim::Name);
            sg::Value src_name_value(src_socket_name, name_type);
            sg::Value dst_name_value(dst_socket_name, name_type);
            sg::Value weight_value(weight, double_type);
            std::list<Value *> dir_entry_list = {&src_name_value, &dst_name_value, &weight_value};
            
            sg::Tuple dir_entry;
            dir_entry.push_value(src_name_value);
            dir_entry.push_value(dst_name_value);
            dir_entry.push_value(weight_value);

            // TODO: Check if there is an existing directory
            // Now just override
            sg::List list_entry;
            list_entry.push_value(dir_entry);

            src_socket.set(list_entry);
        }
        else {
            sg::output("Error, inconsistent types when coupling");
        }
    }
    else {
        sg::output("Error coupling - src_has_dir, src_socket_exists, dst_socket_exists = ");
        sg::output(src_has_dir, src_socket_exists, dst_socket_exists);
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
    // For every socket, store sockets that projected to me in the
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

        // Build projectin_to_me by scanning directories
        projecting_to_me.clear();
        for (auto machine : machines) {
            auto directory = machine.get_socket(sg::Name("directory"));
            if (directory != sg::INVALID) {

            }
            // Dealing with non_existant sockets, either
            // 1. Lemon style- sg::missing
            // 2. exception
            // 3. 
        }
    }
}

}   