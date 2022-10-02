#include "Lexer.h"
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

// Convert string stream to a string
    std::string myFileString = in.str();

// Run Lexer
    Lexer* lexer = new Lexer();
    lexer->Run(myFileString);

    delete lexer;

    return 0;
}