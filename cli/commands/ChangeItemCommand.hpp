#ifndef CHANGE_ITEM_COMMAND_HPP
#define CHANGE_ITEM_COMMAND_HPP

#include "command.hpp"

class ChangeItemCommand:public Command{
public:
    ChangeItemCommand();
    std::string exec();
    std::unique_ptr<Command> clone() const;
};

#endif //CHANGE_ITEM_COMMAND_HPP
