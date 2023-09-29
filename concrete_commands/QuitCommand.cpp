#include "QuitCommand.hpp"

#include "cstdlib"

std::string QuitCommand::exec(Iterator argumentBegin , Iterator argumentEnd, ItemList& items){
    std::exit(0);
}

std::unique_ptr<Command> QuitCommand::clone() const
{
    return std::make_unique<QuitCommand>(*this);
}


//TODO
//  void QuitCommand::addOperand(std::string key, std::string value)
// {
//     throw std::runtime_error("write only [quit]");
// }
