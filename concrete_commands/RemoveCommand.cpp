#include "RemoveCommand.hpp"

std::string RemoveCommand::exec(Document& doc)
{ 
    auto id = *std::next(arguments_.begin()); 
    doc.removeItemFromSlide(std::stoi(id)); 
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
