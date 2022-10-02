#ifndef DATALOG_PROGRAM
#define DATALOG_PROGRAM

#include <vector>
#include "Predicate.h"
#include "Rule.h"

class DatalogProgram {
public:
    void setSchemes(std::vector<Predicate> scheme);
    void setFacts(std::vector<Predicate> fact);
    void setQueries(std::vector<Predicate> queries);
    void setRules(std::vector<Rule> rule);

    std::vector<Predicate> getSchemes();
    std::vector<Predicate> getFacts();
    std::vector<Predicate> getQueries();
    std::vector<Rule> getRules();

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

#endif