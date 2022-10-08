#ifndef DATALOG_PROGRAM
#define DATALOG_PROGRAM

#include <vector>
#include "Predicate.h"
#include "Rule.h"
#include "Token.h"

class DatalogProgram {
public:
// Set Vectors
    void setSchemes(std::vector<Predicate> scheme);
    void setFacts(std::vector<Predicate> fact);
    void setQueries(std::vector<Predicate> queries);
    void setRules(std::vector<Rule> rule);
// Get Vectors
    std::vector<Predicate> getSchemes();
    std::vector<Predicate> getFacts();
    std::vector<Predicate> getQueries();
    std::vector<Rule> getRules();

// Grammar Rules
    void dataLogProgram();
    void scheme();
    void schemeList();
    void fact();
    void factList();
    void rule();
    void ruleList();
    void query();
    void queryList();
    void idList();
    void stringList();
    void predicate();
    void headPredicate();
    void predicateList();
    void parameter();
    void parameterList();

// Match Tokens
    void match(TokenType t);

private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;
}; 

void DatalogProgram::setSchemes(std::vector<Predicate> scheme) {
    DatalogProgram::schemes = scheme;
}


void DatalogProgram::setFacts(std::vector<Predicate> fact) {
    DatalogProgram::facts = fact;
}

void DatalogProgram::setQueries(std::vector<Predicate> query) {
    DatalogProgram::queries = query;
}

void DatalogProgram::setRules(std::vector<Rule> rule) {
    DatalogProgram::rules = rule;
}

std::vector<Predicate> DatalogProgram::getSchemes() {
    return DatalogProgram::schemes;
}

std::vector<Predicate> DatalogProgram::getFacts() {
    return DatalogProgram::facts;
}

std::vector<Predicate> DatalogProgram::getQueries() {
    return DatalogProgram::queries;
}

std::vector<Rule> DatalogProgram::getRules() {
    return DatalogProgram::rules;
}

// Begin Grammar
void DatalogProgram::dataLogProgram() {
// Schemes
    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    scheme();
    schemeList();
// Facts
    match(TokenType::FACTS);
    match(TokenType::COLON);
    factList();
// Rules    
    match(TokenType::RULES);
    match(TokenType::COLON);
    ruleList();
// Queries
    match(TokenType::QUERIES);
    match(TokenType::COLON);
    query();
    queryList();
// EOF
    match(TokenType::ENDFILE);
}

void DatalogProgram::scheme() {}

void DatalogProgram::schemeList() {}

void DatalogProgram::fact() {}

void DatalogProgram::factList() {}

void DatalogProgram::rule() {}

void DatalogProgram::ruleList() {}

void DatalogProgram::query() {}

void DatalogProgram::queryList() {}

void DatalogProgram::idList() {}

void DatalogProgram::stringList() {}

void DatalogProgram::predicate() {}

void DatalogProgram::headPredicate() {}

void DatalogProgram::predicateList() {}

void DatalogProgram::parameter() {}

void DatalogProgram::parameterList() {}


#endif