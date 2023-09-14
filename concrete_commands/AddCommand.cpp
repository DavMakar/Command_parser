#include "AddCommand.hpp"

#include <numeric>

double AddCommand::exec() const{
    return std::accumulate(operands_.begin(), operands_.end(), 0);
}

std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>(*this);
}
