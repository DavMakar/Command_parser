#ifndef GO_SLIDE_COMMAND_HPP
#define GO_SLIDE_COMMAND_HPP

#include "Command.hpp"

class GoSlideCommand: public Command{
public:
    GoSlideCommand();
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //Go_SLIDE_COMMAND_HPP