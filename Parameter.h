#ifndef PARAMETER
#define PARAMETER

#include <vector>
#include <string>

class Parameter {
private:
    std::string parameter_id;

public:
    // Initialize Parameter ID using initializer list
    Parameter(std::string ID) : parameter_id(ID) {}

    // Return ID
    std::string toString() {
        return parameter_id;
    }
};

#endif