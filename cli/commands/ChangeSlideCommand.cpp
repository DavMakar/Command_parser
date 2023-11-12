#include "ChangeSlideCommand.hpp"
#include "../../director.hpp"

std::string ChangeSlideCommand::exec()
{
    auto id = *std::next(arguments_.begin());
    Director::getInstance().changeCurrentSlide(std::stoi(id));
    return "slide changed"; //TODO return from changeCurrentSlide
}

std::unique_ptr<Command> ChangeSlideCommand::clone() const
{
    return std::make_unique<ChangeSlideCommand>();
}
