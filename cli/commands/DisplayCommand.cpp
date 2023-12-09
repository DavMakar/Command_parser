#include "DisplayCommand.hpp"
#include "../../Application.hpp"

DisplayCommand::DisplayCommand()
{
    m_arguments.initArgument("-id",0);
}

void DisplayCommand::exec()
{
    auto id = m_arguments.getArgument<int>("-id");
    Application::instance()->getRenderer().display(Application::instance()->getDocument().getCurrentSlide()->getItemById(id));
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::make_unique<DisplayCommand>();
}
