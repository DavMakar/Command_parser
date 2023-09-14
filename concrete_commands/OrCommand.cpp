#include "OrCommand.hpp"

#include <numeric>

double OrCommand::exec() const
{
    return std::accumulate(operands_.begin() , operands_.end(), 1 , [](double op1 , double op2){
        return op1 || op2;
    });      
}

std::unique_ptr<Command> OrCommand::clone() const
{
    return std::make_unique<OrCommand>(*this);
}

