#include "DisplayCommand.hpp"
#include "../../Application.hpp"

DisplayCommand::DisplayCommand()
{
    m_arguments.initArgument("-id",0);
}

std::string DisplayCommand::exec()
{
    auto id = m_arguments.getArgument<int>("-id");
    return Application::instance().getDirector().displaySlideItem(id);
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::make_unique<DisplayCommand>();
}
