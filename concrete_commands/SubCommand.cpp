#include "SubCommand.hpp"

#include <functional>
#include <numeric>

double SubCommand::exec(const std::vector<double>& operands_) const {
    return std::accumulate(operands_.begin() , operands_.end(), 0 , std::minus<>());
}
