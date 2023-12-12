#include "GoSlideCommand.hpp"
#include "../../Application.hpp"
#include "../../director/actions/GoSlideAction.hpp"

GoSlideCommand::GoSlideCommand()
{
    m_arguments.initArgument("-id", 0);
}

void GoSlideCommand::exec()
{
    auto id = m_arguments.getArgument<int>("-id");
    auto action = std::make_unique<GoSlideAction>(Application::instance()->getDocument(), id);
    Application::instance()->getDirector().runAction(std::move(action));

    Application::instance()->getUiController().logOutput("draw slide");
}

std::unique_ptr<Command> GoSlideCommand::clone() const
{
    return std::make_unique<GoSlideCommand>();
}
