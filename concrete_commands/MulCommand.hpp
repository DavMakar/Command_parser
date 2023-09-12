#ifndef MUL_COMMAND_HPP
#define MUL_COMMAND_HPP

#include "command.hpp"

class MulCommand: public Command{
public: 
    double exec(const std::vector<double>& operands_)const override;
};

#endif //MUL_COMMAND_HPP