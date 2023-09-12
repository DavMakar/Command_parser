#include "QuitCommand.hpp"

#include "cstdlib"

double QuitCommand::exec(const std::vector<double>& operands)const{
    std::exit(0);
}