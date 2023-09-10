#ifndef MUL_COMMAND_HPP
#define MUL_COMMAND_HPP

#include "command.hpp"

class MulCommand: public Command{
public: 
    double exec(const double op1,const double op2)const override;
};

#endif //MUL_COMMAND_HPP