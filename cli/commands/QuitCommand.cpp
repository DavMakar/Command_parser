#include "QuitCommand.hpp"

#include <cstdlib>
#include <QApplication>

std::string QuitCommand::exec(){
    qApp->quit();
}

std::unique_ptr<Command> QuitCommand::clone() const
{
    return std::make_unique<QuitCommand>(*this);
}
