#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "command.hpp"
#include "concrete_commnads.hpp"
#include <memory>
#include <unordered_map>
#include <string>

class Calculator{
    using CommandRegistry = std::unordered_map<std::string, std::unique_ptr<Command>>;
public:    
    Calculator();
    double calculate(const std::string& command, const double op1 , const double op2);

private:
    void initCommandRegistry();

private:
    CommandRegistry register_;
};

#endif //CALCULATOR_HPP