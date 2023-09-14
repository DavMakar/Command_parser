#include "SubCommand.hpp"

#include <functional>
#include <numeric>

double SubCommand::exec() const {
    return std::accumulate(operands_.begin()+1 , operands_.end(), operands_[0] , std::minus<double>{});
}

std::unique_ptr<Command> SubCommand::clone() const
{
    return std::make_unique<SubCommand>(*this);
}