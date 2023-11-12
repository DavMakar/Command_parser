#include "DisplayCommand.hpp"
#include "../../director.hpp"

std::string DisplayCommand::exec()
{
    auto id = *std::next(arguments_.begin());
    return Director::getInstance().displaySlideItem(std::stoi(id));
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::make_unique<DisplayCommand>();
}
