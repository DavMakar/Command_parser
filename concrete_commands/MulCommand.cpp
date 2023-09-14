#include "MulCommand.hpp"

#include <functional>
#include <numeric>

double MulCommand::exec()const {
    return std::accumulate(operands_.begin() , operands_.end(), 1, std::multiplies<>());
}

std::unique_ptr<Command> MulCommand::clone() const
{
    return std::make_unique<MulCommand>(*this);
}

