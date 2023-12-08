#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include "Command.hpp"

class ListCommand: public Command{
public:
    void exec() override;
    std::unique_ptr<Command> clone() const override; 
};

#endif //LIST_COMMAND_HPP
