#include "ListCommand.hpp"
#include "../../Application.hpp"

std::string ListCommand::exec()
{
    return Application::instance().getDirector().displayAllSlides();
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}