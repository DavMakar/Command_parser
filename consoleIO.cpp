#include "consoleIO.hpp"
#include <iostream>
#include <string>

void ConsoleIO::printOutput(std::string_view output){
    std::cout << output << std::endl;
}

std::string ConsoleIO::getInput(std::string_view msg){
    std::cout<<msg;
    std::string input;
    std::getline(std::cin , input);
    return input;
}