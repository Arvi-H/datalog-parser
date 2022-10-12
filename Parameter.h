#ifndef PARAMETER
#define PARAMETER

#include <vector>
#include <string>

class Parameter {
private:
    std::string parameter_id;

public:
    // Set Parameter ID  
    void setID(std::string ID);

    // Return ID
    std::string toString() const;
};

#endif