#include "DivCommand.hpp"

#include <numeric>
#include <functional>

double DivCommand::exec() const {
    if(operands_.size() <= 1){
        throw std::runtime_error("less operands");
    }
    return std::accumulate(operands_.begin() + 1, operands_.end(), operands_[0], std::divides<>());
}

std::unique_ptr<Command> DivCommand::clone() const
{
    return std::make_unique<DivCommand>(*this);
}
