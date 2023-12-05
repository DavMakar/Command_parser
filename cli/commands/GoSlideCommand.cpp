#include "GoSlideCommand.hpp"
#include "../../Application.hpp"
GoSlideCommand::GoSlideCommand()
{
    m_arguments.initArgument("-id", 0);
}

std::string GoSlideCommand::exec()
{
    auto id = m_arguments.getArgument<int>("-id");
    Application::instance().getDirector().changeCurrentSlide(id);    
    return "slide changed"; //TODO return from changeCurrentSlide
}

std::unique_ptr<Command> GoSlideCommand::clone() const
{
    return std::make_unique<GoSlideCommand>();
}
