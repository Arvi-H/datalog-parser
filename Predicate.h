#ifndef PREDICATE
#define PREDICATE

#include <vector>
#include <string>
#include "Parameter.h"

class Predicate {
private:
    std::vector<Parameter> parameters;
    std::string id;
};

#endif