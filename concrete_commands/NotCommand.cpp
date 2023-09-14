#include "NotCommand.hpp"

#include <stdexcept>

double NotCommand::exec() const
{
    if(operands_.size() > 1){
        throw std::runtime_error("command works with one operand");
    }
    return !operands_[0];
}

std::unique_ptr<Command> NotCommand::clone() const
{
    return std::make_unique<NotCommand>(*this);
}

