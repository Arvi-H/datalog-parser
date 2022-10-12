#ifndef PREDICATE
#define PREDICATE

#include <iostream>
#include <vector>
#include <string>
#include "Parameter.h"

class Predicate {
private:
    std::vector<Parameter> parameters;
    std::string predicate_id;

public:
    // Initialize Predicate ID using Initializer list
    Predicate(std::string ID) : predicate_id(ID) {}

    // Add parameter to the paramteres vector
    void addParameter(Parameter p); 

    // Print Parameters
    void toString();
};

#endif