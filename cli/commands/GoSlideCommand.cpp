#include "GoSlideCommand.hpp"
#include "../../director/Director.hpp"

GoSlideCommand::GoSlideCommand()
{
    arguments_.initArgument("-id", 0);
}

std::string GoSlideCommand::exec()
{
    auto id = arguments_.getArgument<int>("-id");
    Director::getInstance().changeCurrentSlide(id);
    return "slide changed"; //TODO return from changeCurrentSlide
}

std::unique_ptr<Command> GoSlideCommand::clone() const
{
    return std::make_unique<GoSlideCommand>();
}
