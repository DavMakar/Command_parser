#ifndef UNDO_COMMAND_HPP
#define UNDO_COMMAND_HPP

#include "Command.hpp"
#include <unordered_set>

class UndoCommand: public Command{
public:
    void exec() override;
    std::unique_ptr<Command> clone() const override;
};

#endif //UNDO_COMMAND_HPP
