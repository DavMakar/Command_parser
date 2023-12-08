#ifndef DISPLAY_COMMAND_HPP
#define DISPLAY_COMMAND_HPP

#include "Command.hpp"
#include <unordered_set>

class DisplayCommand: public Command{
public:
    DisplayCommand();
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //DISPLAY_COMMAND_HPP
