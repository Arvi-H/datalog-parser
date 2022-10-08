#ifndef PREDICATE
#define PREDICATE

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

void Predicate::addParameter(Parameter p) {
    parameters.push_back(p);
}

void Predicate::toString() {
    // Print predicate ID and begin formatting
    std::cout << predicate_id << "(";
    
    // Run loop until last item for formatting purposes
    for (unsigned int i = 0; i < parameters.size()-1; i++) {
        std::cout << parameters.at(i).toString() << ",";
    }
    // Print Last Index w/ formatting
    unsigned int lastIndex = parameters.size() - 1; 
    std::cout << parameters.at(lastIndex).toString() << ")";
}

#endif