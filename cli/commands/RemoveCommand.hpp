#ifndef REMOVE_COMMAND_HPP
#define REMOVE_COMMAND_HPP

#include "command.hpp"

class RemoveCommand:public Command{
public:
    RemoveCommand();
    std::string exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //REMOVE_COMMAND_HPP