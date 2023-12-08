#ifndef REDO_COMMAND_HPP
#define REDO_COMMAND_HPP

#include "Command.hpp"
#include <unordered_set>

class RedoCommand: public Command{
public:
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //REDO_COMMAND_HPP
