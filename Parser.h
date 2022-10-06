#ifndef PARSER
#define PARSER

#include <vector>
#include <string>
#include <iostream>
#include "DatalogProgram.h"
#include "Token.h"

class Parser {
private:
    std::vector<Token> tokens;
    DatalogProgram program;
    DatalogProgram Parse();

public:
    Parser(const std::vector<Token> &t);
    void match(TokenType t);
    int index = 0;
};

// Parser object reqires a vector of tokens
Parser::Parser(const std::vector<Token> &t) : tokens(t) {}

// Useful function to check if the tokentype argument matches the tokentype of the vector at that index
void Parser::match(TokenType t){
    if (t == tokens.at(index).getTokenType()) {
        index++;
    } else {
        throw(tokens.at(index));
    }
}

// Start Parser
DatalogProgram Parser::Parse() {
    try {
        program.dataLogProgram();
    } catch (Token t) {
        std::cout << t.toString() << std::endl;
    }
}

#endif