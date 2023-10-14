#include "RemoveCommand.hpp"

std::string RemoveCommand::exec(ItemList &items)
{ 
    auto id = *std::next(arguments_.begin());
    items.erase(id);
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
