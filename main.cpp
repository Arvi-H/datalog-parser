#include "Lexer.h"
#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
 
int main(int argc, char** argv) {
// File I/O
    std::ifstream input(argv[1]);
    std::stringstream in;

// Convert file to a string stream
    input.open(argv[1]);
    in << input.rdbuf();
    input.close();

// Convert string stream to a sting
    std::string myFileString = in.str();

// Run Lexer
    Lexer* lexer = new Lexer();
    lexer->Run(myFileString);

    Parser* parser = new Parser(lexer->getTokens());
    parser->Parse();

// Free memory
    delete lexer;
    delete parser;

    return 0;
}