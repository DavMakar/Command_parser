#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "Command.hpp"

class Director;

class SaveCommand:public Command{
public:
    SaveCommand();
    void exec() override;
    std::unique_ptr<Command> clone() const override; 
};

#endif //SAVE_COMMAND_HPP
