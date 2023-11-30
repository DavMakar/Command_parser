#ifndef GO_SLIDE_COMMAND_HPP
#define GO_SLIDE_COMMAND_HPP

#include "command.hpp"

class GoSlideCommand: public Command{
public:
    GoSlideCommand();
    std::string exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //Go_SLIDE_COMMAND_HPP