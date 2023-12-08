#ifndef CHANGE_ITEM_COMMAND_HPP
#define CHANGE_ITEM_COMMAND_HPP

#include "Command.hpp"

class ChangeItemCommand:public Command{
public:
    ChangeItemCommand();
    void exec();
    std::unique_ptr<Command> clone() const;
};

#endif //CHANGE_ITEM_COMMAND_HPP
