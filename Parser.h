#ifndef PARSER
#define PARSER

#include <vector>
#include <string>
#include "DatalogProgram.h"
#include "Token.h"

class Parser {
private:
    std::vector<Token> tokens;
    DatalogProgram program;

    DatalogProgram Parse();
};

#endif