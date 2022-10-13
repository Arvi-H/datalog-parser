#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"
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
    Lexer lexer;
    lexer.Run(myFileString);

    try {
        // Run Parser 
        Parser parser(lexer.getTokens());
        DatalogProgram program = parser.Parse();
        std::cout << "Success!" << std::endl;
        std::cout << program.toString();
        
    // Catch Errors
    } catch (Token* errorToken) {
        std::cout << "Failure!" << std::endl << "  " << errorToken->toString();
    } 
 
    return 0;
}