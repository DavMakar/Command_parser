#include "MulCommand.hpp"

#include <functional>
#include <numeric>

double MulCommand::exec(const std::vector<double>& operands_) const {
    return std::accumulate(operands_.begin() , operands_.end(), 1, std::multiplies<>());
}