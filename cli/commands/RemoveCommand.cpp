#include "RemoveCommand.hpp"
#include "../../Application.hpp"

RemoveCommand::RemoveCommand()
{
    m_arguments.initArgument("-id",0);
}

std::string RemoveCommand::exec()
{ 
    auto id = m_arguments.getArgument<int>("-id"); 
    Application::instance().getDirector().removeItemFromSlide(id);
    return "erased";
}

std::unique_ptr<Command> RemoveCommand::clone() const
{
    return std::make_unique<RemoveCommand>();
}
