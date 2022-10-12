#include "Parser.h" 

// Constructor to copy the vector of tokens
Parser::Parser(const std::vector<Token*> tokensCopy) {
    for (auto i : tokensCopy){
        tokens.push_back(i);
    }
}

// Start Parser
DatalogProgram Parser::Parse() {
    try {
        dataLogProgram();
        return program;
    } catch (Token &t) {
        std::cout << "Failure  " << std::endl << t.toString() << std::endl;
    }
}

// Useful function to check if the tokentype argument matches the tokentype of the vector at that index
bool Parser::match(std::string tokenName) {
    if (tokenName == tokens.at(index)->getTokenName()) {
        index++;
        skipComments();
    } else {  
        throw(tokens.at(index));
    }
}

// Useful function to skip over the comment tokens
void Parser::skipComments() {
    if (tokens.at(index)->getTokenName() == "COMMENT") { 
        index++; 
    }

    if (tokens.at(index)->getTokenName() == "COMMENT") { 
        skipComments(); 
    }
}

// datalogProgram  ->  SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
void Parser::dataLogProgram() {
// Check for comments
    skipComments();
// Schemes
    match("SCHEMES");
    match("COLON");
    scheme();
    schemeList();
// Facts
    match("FACTS");
    match("COLON");
    factList();
// Rules    
    match("RULES");
    match("COLON");
    ruleList();
// Queries
    match("QUERIES");
    match("COLON");
    query();
    queryList();
// EOF
    match("ENDFILE");
}

// scheme  ->  ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::scheme() {
    Predicate scheme;
    Parameter parameter;
    
    // Check for ID
    match();
    scheme.setID(tokens.at(index-1)->getTokenDescription());
    
    // Check for Left Paren
    match("LEFT_PAREN");

    // Check for ID
    match();

    // Add Param
    parameter.setID(tokens.at(index-1)->getTokenDescription());
    scheme.addParameter(parameter);

    // Call idList
    idList(scheme);

    // Check for Right Paren
    match("RIGHT_PAREN");

    // Push the scheme
    program.setSchemes(scheme);
}

// schemeList  ->  scheme schemeList | lambda
void Parser::schemeList() {
    if (match()) {
        scheme();
        schemeList();
    }
}

//fact  ->  ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
void Parser::fact() {
    Predicate fact;
    Parameter parameter;
    
    // Check for ID
    match();
    fact.setID(tokens.at(index-1)->getTokenDescription());
    
    // Check for Left Paren
    match("LEFT_PAREN");

    // Check for String
    match("STRING");
    program.setFactsDomain(tokens.at(index-1)->getTokenDescription());
    
    // Add Param
    parameter.setID(tokens.at(index - 1)->getTokenDescription());
    fact.addParameter(parameter);

    // Call stringList
    stringList(fact);

    // Check for Right Paren
    match("RIGHT_PAREN");

    // Check for Period
    match("PERIOD");

    program.setFacts(fact);
}

// factList  ->  fact factList | lambda
void Parser::factList() {
    if (match()) {
        fact();
        factList();
    }
}

// rule  ->  headPredicate COLON_DASH predicate predicateList PERIOD
void Parser::rule() {
    Predicate ruleHead;
    Predicate rules;
    Rule rule;

    // Call headPredicate
    headPredicate(ruleHead);

    // Set Rule Head
    rule.setPredicateHeadID(ruleHead);
    
    // Check for COLON DASH
    match("COLON_DASH");

    // Call predicate
    predicate(rules);

    // Set Rule vector of Predicates
    rule.setPredicates(rules);

    // Call predicateList
    predicateList(rule);

    // Check for Period
    match("PERIOD");

    program.setRules(rule); 
}

// ruleList  ->  rule ruleList | lambda
void Parser::ruleList() {
    if (match()) {
        rule();
        ruleList();
    }
}

// query  ->  predicate Q_MARK
void Parser::query() {
    Predicate query;

    // Call predicate
    predicate(query);

    // Check for Question Mark
    match("Q_MARK");

    program.setQueries(query);
}

// Parse Query List
void Parser::queryList() {
    if (match()) {
        query();
        queryList();
    }
}

// idList  ->  COMMA ID idList | lambda
void Parser::idList(Predicate& predicate) {
    // Check for Comma
    if (match("COMMA")) {
        Parameter p;

        // Check for ID
        match();

        // Add Parameter
        p.setID(tokens.at(index-1)->getTokenDescription());
        predicate.addParameter(p);
        
        // Call idList
        idList(predicate);
    }
}

// stringList  ->  COMMA STRING stringList | lambda
void Parser::stringList(Predicate& predicate) {
    if (match("COMMA")) {
        Parameter p;
        
        // Check for comma
        match("COMMA");
        
        // Check for string
        match("STRING");

        // Add Parameter
        program.setFactsDomain(tokens.at(index-1)->getTokenDescription());
        p.setID(tokens.at(index-1)->getTokenDescription());
        predicate.addParameter(p);

        stringList(predicate);
    }
}

// predicate  ->  ID LEFT_PAREN parameter parameterList RIGHT_PAREN
void Parser::predicate(Predicate& predicate) {
    // Check for ID
    match();

    // Add predicate ID
    predicate.setID(tokens.at(index-1)->getTokenDescription());
    
    // Check for Left Paren
    match("LEFT_PAREN");

    // Call Parameter
    parameter(predicate);
    
    // Call ParameterList
    parameterList(predicate);
    
    // Check for right paren
    match("RIGHT_PAREN");
}

// headPredicate  ->  ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::headPredicate(Predicate& predicate) {
    Parameter param;

    // Check for ID
    match();
    predicate.setID(tokens.at(index-1)->getTokenDescription());

    // Check for left paren
    match("LEFT_PAREN");

    // Check for ID
    match();

    // Add parameter to predicate
    param.setID(tokens.at(index-1)->getTokenDescription());
    predicate.addParameter(param);

    // Call idList
    idList(predicate);

    // Check for right paren
    match("RIGHT_PAREN");
}

void Parser::predicateList(Rule& rule) {

}

void Parser::parameter(Predicate& predicate) {

}

void Parser::parameterList(Predicate& predicate) {

}

