#include "Predicate.h"

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