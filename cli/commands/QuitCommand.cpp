#include "QuitCommand.hpp"

#include <cstdlib>

std::string QuitCommand::exec(){
    std::exit(0);
}

std::unique_ptr<Command> QuitCommand::clone() const
{
    return std::make_unique<QuitCommand>(*this);
}
