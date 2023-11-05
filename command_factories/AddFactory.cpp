#include "AddFactory.hpp"
#include "../commands/AddCommand.hpp"

std::unique_ptr<Command> AddFactory::makeCommand(const std::vector<std::string> &args)
{   
    validateArgs(args);

    auto command = std::make_unique<AddCommand>();
    command->setArguments(args);
    return command;
}

void AddFactory::validateArgs(const std::vector<std::string> &args)
{
    if(validOptions.find(*args.begin()) == validOptions.end()){
        throw std::runtime_error("to add item write -name [Item name]");
    }
}

std::unique_ptr<CommandFactory> AddFactory::clone() const
{
    return std::make_unique<AddFactory>();
}
