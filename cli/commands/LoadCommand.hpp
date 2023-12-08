#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "Command.hpp"

class LoadCommand:public Command{
public:
    LoadCommand();
    void exec() override;
    std::unique_ptr<Command> clone() const override; 
};

#endif //LOAD_COMMAND_HPP
