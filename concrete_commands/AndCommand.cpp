#include "AndCommand.hpp"

#include <numeric>

double AndCommand::exec(const std::vector<double> &operands_) const{ 
    return std::accumulate(operands_.begin() , operands_.end(), 1 , [](double op1 , double op2){
        return op1 && op2;
    });      
}