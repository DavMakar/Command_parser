#include "NotCommand.hpp"

#include <stdexcept>

double NotCommand::exec(const std::vector<double> &operands_) const
{
    if(operands_.size() > 1){
        throw std::runtime_error("command works with one operand");
    }
    return !operands_[0];
}