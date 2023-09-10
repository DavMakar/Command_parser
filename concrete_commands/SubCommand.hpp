#ifndef SUB_COMMAND_HPP
#define SUB_COMMAND_HPP

#include "command.hpp"

class SubCommand : public Command {
public:
    double exec(const double op1, const double op2) const override;
};

#endif // SUB_COMMAND_HPP
