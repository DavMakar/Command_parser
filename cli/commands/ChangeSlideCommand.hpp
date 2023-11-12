#ifndef CHANGE_SLIDE_COMMAND_HPP
#define CHANGE_SLIDE_COMMAND_HPP

#include "command.hpp"

class ChangeSlideCommand: public Command{
public:
    std::string exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //CHANGE_SLIDE_COMMAND_HPP