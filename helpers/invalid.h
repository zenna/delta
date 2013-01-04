/*Invalid structure*/
#pragma once
#include "sigma/machines/machines.h"

namespace sg {

const sg::VariableSocket INVALID_SOCKET; 

bool is_invalid(sg::VariableSocket const &skt) {
    return (skt == INVALID_SOCKET);
}
}