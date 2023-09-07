#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

#include "calculator.hpp"
#include "command_parser.hpp"

int main(){
    std::string input;
    std::copy(std::istreambuf_iterator<char>(std::cin) , std::istreambuf_iterator<char>() 
    , back_inserter(input));
    
    std::stringstream ss(input);

    CommandParser inputParser;

    auto [operation , operator1, operator2] = inputParser.parse(ss);

    Calculator calc;
    
    std::cout << calc.calculate(operation,operator1,operator2) <<std::endl;
}