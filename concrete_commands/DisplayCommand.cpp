#include "DisplayCommand.hpp"

std::string DisplayCommand::exec(ItemList& items)
{
    auto id = *std::next(arguments_.begin());
    return items[id]->info();
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::make_unique<DisplayCommand>();
}
