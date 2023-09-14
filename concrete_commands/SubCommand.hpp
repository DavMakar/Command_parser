#ifndef SUB_COMMAND_HPP
#define SUB_COMMAND_HPP

#include "command.hpp"

class SubCommand : public Command {
public:
    double exec() const override;
    std::unique_ptr<Command> clone() const override;   
};

#endif // SUB_COMMAND_HPP
