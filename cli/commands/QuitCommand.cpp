#include "QuitCommand.hpp"
#include "../../Application.hpp"

void QuitCommand::exec(){
    Application::instance()->quit();
}

std::unique_ptr<Command> QuitCommand::clone() const
{
    return std::make_unique<QuitCommand>(*this);
}
