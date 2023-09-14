#include "QuitCommand.hpp"

#include "cstdlib"

double QuitCommand::exec()const{
    std::exit(0);
}

std::unique_ptr<Command> QuitCommand::clone() const
{
    return std::make_unique<QuitCommand>(*this);
}

void QuitCommand::addOperand(std::string key, std::string value)
{
    throw std::runtime_error("write only [quit]");
}
