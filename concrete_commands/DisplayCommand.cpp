#include "DisplayCommand.hpp"

std::string DisplayCommand::exec(Iterator argumentBegin, Iterator argumentEnd, ItemList& items)
{
    if(args.find(*argumentBegin) == args.end()){
        throw std::runtime_error("to display item write -id [Item id]");
    }
    auto id = *std::next(argumentBegin);
    return items[id]->info();
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::unique_ptr<DisplayCommand>();
}
