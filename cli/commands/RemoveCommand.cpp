#include "RemoveCommand.hpp"
#include "../../director.hpp"

std::string RemoveCommand::exec()
{ 
    auto itemId = std::stoi(*std::next(arguments_.begin())); 
    Director::getInstance().removeItemFromSlide(itemId);
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
