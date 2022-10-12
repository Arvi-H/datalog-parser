#include "Rule.h"

void Rule::setHeadPredicateParameter(Parameter parameter) {
    head_id.addParameter(parameter);
}

void Rule::seRulePredicates(Predicate predicate) {
    predicates.push_back(predicate);
}

