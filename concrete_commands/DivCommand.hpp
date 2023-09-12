#ifndef DIV_COMMAND_HPP
#define DIV_COMMAND_HPP

#include "command.hpp"

class DivCommand : public Command {
public:
    double exec(const std::vector<double>& operands) const override;
};

#endif // DIV_COMMAND_HPP
