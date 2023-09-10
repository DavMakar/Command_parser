#ifndef DIV_COMMAND_HPP
#define DIV_COMMAND_HPP

#include "command.hpp"

class DivCommand : public Command {
public:
    double exec(const double op1, const double op2) const override;
};

#endif // DIV_COMMAND_HPP
