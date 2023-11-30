#include "ListCommand.hpp"
#include "../../director/Director.hpp"

std::string ListCommand::exec()
{
    return Director::getInstance().displayAllSlides();
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}