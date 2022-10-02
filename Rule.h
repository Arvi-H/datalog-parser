#ifndef RULE
#define RULE

#include <vector>
#include <string>
#include "Predicate.h"

class Rule {
private:
    std::vector<Predicate> predicates;
    Predicate head;
};

#endif