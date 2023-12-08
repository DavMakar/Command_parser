#ifndef DRAW_COMMAND_HPP
#define DRAW_COMMAND_HPP

#include "Command.hpp"
#include <unordered_set>

class DrawCommand: public Command{
public:
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //DRAW_COMMAND_HPP
