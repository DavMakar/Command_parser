#include "DivCommand.hpp"

#include <numeric>
#include <functional>

double DivCommand::exec(const std::vector<double>& operands_) const {
    return std::accumulate(operands_.begin() + 1, operands_.end(), operands_[0], std::divides<>());
}
