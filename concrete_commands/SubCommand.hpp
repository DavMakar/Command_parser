#ifndef SUB_COMMAND_HPP
#define SUB_COMMAND_HPP

#include "command.hpp"

class SubCommand : public Command {
public:
    double exec(const std::vector<double>& operands) const override;
};

#endif // SUB_COMMAND_HPP
