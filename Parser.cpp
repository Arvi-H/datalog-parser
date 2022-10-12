#include "Parser.h" 
#include <utility>

// Constructor to copy the vector of tokens
Parser::Parser(const std::vector<Token*> t) {
    tokens = std::move(t);
}

// Start Parser
DatalogProgram Parser::Parse() {
    try {
        dataLogProgram();
    } catch (Token &t) {
        std::cout << "Failure  " << std::endl << t.toString() << std::endl;
    }
}

// Useful function to check if the tokentype argument matches the tokentype of the vector at that index
bool Parser::match(std::string tokenName) {
    // Check for comments
    if (tokenName == "COMMENT") { 
        index++; 
    }

    // Check for multiline comments
    if (tokenName == "COMMENT") { 
        match(tokenName); 
    }

    // If tokens match, increment 
    if (tokenName == tokens.at(index)->getTokenName()) {
        index++;
        return true;
    } else { // throw that token & return false
        throw(tokens.at(index));
    }
}

// datalogProgram  ->  SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
void Parser::dataLogProgram() {
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
    // Push predicate to scheme list
    if (match()) {
        Predicate predicate(tokens[index]->getTokenDescription());
        program.setSchemes(predicate);
    }

    // Check for left parenthesis
    match("LEFT_PAREN");

    // Push parameter to scheme list Predicate's parameter vector
    if (match()) {
        Parameter parameter(tokens[index]->getTokenDescription());
        program.setSchemeParameters(parameter);
    }
    
    // Call idList
    idList();

    // Check for right parenthesis
    match("RIGHT_PAREN");
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
    // Push predicate to scheme list
    if (match()) {
        Predicate predicate(tokens[index]->getTokenDescription());
        program.setFacts(predicate);
    }

    // Check for left parenthesis
    match("LEFT_PAREN");
    
    // Push parameter to fact list Predicate's parameter vector
    if (match("STRING")) {
        std::string tokenDescription = tokens[index]->getTokenDescription();
  
        Parameter parameter(tokenDescription);
        program.setFactsParameters(parameter);

        // Push fact domain to the fact domain vector
        program.setFactsDomain(tokenDescription);
    }
  
    // Call stringList
    stringList();
    
    // Check for right parenthesis
    match("RIGHT_PAREN");

    // Check for period
    match("PERIOD");
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
    // Call headPredicate
    headPredicate();
    
    // Check for COLON DASH
    match("COLON_DASH");

    // Call predicate
    predicate();

    // Call predicateList
    predicateList();

    // Check for Period
    match("PERIOD");
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
    // Call predicate
    predicate();

    // Check for Question Mark
    match("Q_MARK");
}

// Parse Query List
void Parser::queryList() {
    if (match()) {
        query();
        queryList();
    }
}


void Parser::idList() {

}

void Parser::stringList() {

}

void Parser::predicate() {

}

void Parser::headPredicate() {

}

void Parser::predicateList() {

}

void Parser::parameter() {

}

void Parser::parameterList() {

}

