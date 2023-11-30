#include "RemoveCommand.hpp"
#include "../../director/Director.hpp"

RemoveCommand::RemoveCommand()
{
    arguments_.initArgument("-id",0);
}

std::string RemoveCommand::exec()
{ 
    auto id = arguments_.getArgument<int>("-id"); 
    Director::getInstance().removeItemFromSlide(id);
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
