#ifndef CREATE_SLIDE_COMMAND_HPP
#define CREATE_SLIDE_COMMAND_HPP

#include "Command.hpp"

class CreateSlideCommand: public Command{
public:
    CreateSlideCommand();
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //CREATE_SLIDE_COMMAND_HPP
