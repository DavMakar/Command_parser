#ifndef CHANGE_ITEM_COMMAND_HPP
#define CHANGE_ITEM_COMMAND_HPP

#include "command.hpp"

class ChangeItemCommand:public Command{
    std::string exec(IDocument& doc);
    std::unique_ptr<Command> clone() const;
};

#endif //CHANGE_ITEM_COMMAND_HPP
