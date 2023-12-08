#include "UndoCommand.hpp"
#include "../../Application.hpp"

void UndoCommand::exec()
{
    Application::instance()->getDirector().undoAction();
    Application::instance()->getController().logOutput("undo");
}

std::unique_ptr<Command> UndoCommand::clone() const
{
    return std::make_unique<UndoCommand>();
}
