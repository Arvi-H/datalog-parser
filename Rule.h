#ifndef RULE
#define RULE

#include <vector>
#include <string>
#include "Predicate.h"

class Rule {
private:
    Predicate head_id;
    std::vector<Predicate> predicates;
public:
    // Initialize Head ID using Initializer list
    Rule(Predicate ID) : head_id(ID) {}

    void setHeadPredicateParameter(Parameter parameter);
    void seRulePredicates(Predicate predicate);
};

#endif