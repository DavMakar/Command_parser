#include "RedoCommand.hpp"
#include "../../Application.hpp"

void RedoCommand::exec()
{
    Application::instance()->getDirector().redoAction();
    Application::instance()->getUiController().logOutput("redo");
}

std::unique_ptr<Command> RedoCommand::clone() const
{
    return std::make_unique<RedoCommand>();
}
