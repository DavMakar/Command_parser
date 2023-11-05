#include "RemoveCommand.hpp"

std::string RemoveCommand::exec(Document& doc)
{ 
    auto id = *std::next(arguments_.begin()); 
    documentDirector_.removeItemFromSlide(doc,std::stoi(id));
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
