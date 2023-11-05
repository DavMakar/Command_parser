#include "consoleIO.hpp"
#include <iostream>
#include <iterator>
#include <sstream>

void ConsoleIO::printOutput(std::string_view output){
    std::cout << output << std::endl;
}

TokenVector ConsoleIO::getInput(std::string_view msg){
    std::cout<< msg;
    Token input;
    std::getline(std::cin, input);
    std::istringstream iss{input};
    TokenVector tokens(std::istream_iterator<std::string>{iss} , {});
    return tokens;
}
