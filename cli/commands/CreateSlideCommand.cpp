#include "CreateSlideCommand.hpp"
#include "../../Application.hpp"
#include "../../director/actions/CreateSlideAction.hpp"

CreateSlideCommand::CreateSlideCommand()
{
}

void CreateSlideCommand::exec()
{
    auto action = std::make_unique<CreateSlideAction>(Application::instance()->getDocument());
    Application::instance()->getDirector().runAction(std::move(action));
        
    Application::instance()->getUiController().logOutput("added slide");
}

std::unique_ptr<Command> CreateSlideCommand::clone() const
{
    return std::make_unique<CreateSlideCommand>();
}
