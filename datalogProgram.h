#ifndef DATALOG_PROGRAM
#define DATALOG_PROGRAM

#include <vector>

#include "Predicate.h"
#include "Rule.h"
#include "Token.h"

class DatalogProgram {
public:
// Set Vectors
    void setSchemes(Predicate scheme);
    void setFacts(Predicate fact);
    void setFactsDomain(std::string domain);
    void setQueries(Predicate queries);
    void setRules(Rule rule);

// Set Paramteters for each Predicate Vector
    void setSchemeParameters(Parameter parameter);
    void setFactsParameters(Parameter parameter);
    void setQueriesParameters(Parameter parameter);

private:
// Parser Vectors
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<std::string> factsDomain;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;
};

#endif