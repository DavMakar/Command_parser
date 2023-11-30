#include "DisplayCommand.hpp"
#include "../../director/Director.hpp"

DisplayCommand::DisplayCommand()
{
    arguments_.initArgument("-id",0);
}

std::string DisplayCommand::exec()
{
    auto id = arguments_.getArgument<int>("-id");
    return Director::getInstance().displaySlideItem(id);
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::make_unique<DisplayCommand>();
}
