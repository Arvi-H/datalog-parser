#include "DatalogProgram.h"

// Push predicate to the schemes vectors.
void DatalogProgram::setSchemes(Predicate scheme) {
    DatalogProgram::schemes.push_back(scheme);
}

// Push predicate to the facts vectors.
void DatalogProgram::setFacts(Predicate fact) {
    DatalogProgram::facts.push_back(fact);
}

// Push to the facts domain
void DatalogProgram::setFactsDomain(std::string domain) {
    factsDomain.push_back(domain);
}

// Push predicate to the queries vectors.
void DatalogProgram::setQueries(Predicate query) {
    DatalogProgram::queries.push_back(query);
}

// Push rule to the rules vector
void DatalogProgram::setRules(Rule rule) {
    DatalogProgram::rules.push_back(rule);
}

// Push parameters to the vector of parameters of the last predicate of the scheme vectors.
void DatalogProgram::setSchemeParameters(Parameter parameter) {
    int lastPredicateIndex = schemes.size()-1;

    // Push parameter to the vector of parameters of the last predicate of the scheme vector
    schemes[lastPredicateIndex].addParameter(parameter);    
}

// Push parameters to the vector of parameters of the last predicate of the facts vectors.
void DatalogProgram::setFactsParameters(Parameter parameter) {
    int lastPredicateIndex = facts.size()-1;

    // Push parameter to the vector of parameters of the last predicate of the facts vector
    facts[lastPredicateIndex].addParameter(parameter);    
}

// Push parameters to the vector of parameters of the last predicate of the queries vectors.
void DatalogProgram::setQueriesParameters(Parameter parameter) {
    int lastPredicateIndex = queries.size()-1;

    // Push parameter to the vector of parameters of the last predicate of the queries vector
    queries[lastPredicateIndex].addParameter(parameter);    
}

 