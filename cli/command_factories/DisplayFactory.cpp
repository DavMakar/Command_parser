#include "DisplayFactory.hpp"
#include "../commands/DisplayCommand.hpp"
#include <stdexcept>

std::unique_ptr<Command> DisplayFactory::makeCommand(const std::vector<std::string> &args)
{   
    validateArgs(args);
   
    auto command = std::make_unique<DisplayCommand>();
    command->setArguments(args);
    return command;
}

void DisplayFactory::validateArgs(const std::vector<std::string> &args)
{
    if(validOpts.find(*args.begin()) == validOpts.end()){
        throw std::runtime_error("to display item write -id [Item id]");
    }
}

std::unique_ptr<CommandFactory> DisplayFactory::clone() const
{
    return std::make_unique<DisplayFactory>();
}
