#ifndef QUIT_COMMAND_HPP
#define QUIT_COMMAND_HPP

#include "command.hpp"

class QuitCommand:public Command{
public:
    std::string exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //QUIT_COMMAND_HPP