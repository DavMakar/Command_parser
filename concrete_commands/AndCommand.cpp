#include "AndCommand.hpp"

#include <numeric>

double AndCommand::exec() const{ 
    return std::accumulate(operands_.begin() , operands_.end(), 1 , [](double op1 , double op2){
        return op1 && op2;
    });      
}

std::unique_ptr<Command> AndCommand::clone() const
{
    return std::make_unique<AndCommand>(*this);
}
