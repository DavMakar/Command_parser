#include "consoleIO.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

void ConsoleIO::printOutput(std::string_view output){
    std::cout << output << std::endl;
}

void ConsoleIO::tokenizeInput(){
    std::copy(std::istream_iterator<Token>{std::cin},
              std::istream_iterator<Token>(), std::back_inserter(inputTokens));
}

TokenVector ConsoleIO::getInput(){
    tokenizeInput();
    TokenVector tmp = std::move(inputTokens);
    return tmp;
}