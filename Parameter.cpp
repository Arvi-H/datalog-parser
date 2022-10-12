#include "Parameter.h"

void Parameter::setID(std::string ID) {
    parameter_id = ID;
}

std::string Parameter::toString() const {
    return parameter_id;
}