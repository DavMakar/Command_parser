#include "QuitCommand.hpp"
#include <QApplication>

std::string QuitCommand::exec(){
    qApp->quit();
    return "quit";
}

std::unique_ptr<Command> QuitCommand::clone() const
{
    return std::make_unique<QuitCommand>(*this);
}
