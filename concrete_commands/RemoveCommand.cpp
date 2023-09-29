#include "RemoveCommand.hpp"

std::string RemoveCommand::exec(Iterator argumentBegin, Iterator argumentEnd, ItemList &items)
{
    if(args.find(*argumentBegin) == args.end()){
        throw std::runtime_error("to remove item write -id [Item id]");
    }
    auto id = *std::next(argumentBegin);
    items.erase(id);
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
