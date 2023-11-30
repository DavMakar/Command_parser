#include "consoleIO.hpp"
#include <iostream>
#include <iterator>
#include <sstream>

void ConsoleIO::printOutput(std::string_view output){
    std::cout << output << std::endl;
}

std::istringstream ConsoleIO::getInput(std::string_view msg){
    std::cout << msg;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss{input};
    return iss;
}
