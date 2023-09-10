#include "QuitCommand.hpp"

#include "cstdlib"

double QuitCommand::exec(const double op1,const double op2)const{
    std::exit(0);
}