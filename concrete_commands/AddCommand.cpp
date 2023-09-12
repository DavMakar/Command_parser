#include "AddCommand.hpp"

#include <numeric>

double AddCommand::exec(const std::vector<double>& operands_) const{
    return std::accumulate(operands_.begin(), operands_.end(), 0);
}
