#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "Command.hpp"

class RemoveCommand:public Command{
public:
    RemoveCommand();
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //REMOVE_COMMAND_HPP