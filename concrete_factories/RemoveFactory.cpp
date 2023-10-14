#include "RemoveFactory.hpp"
#include "../concrete_commands/RemoveCommand.hpp"

std::unique_ptr<Command> RemoveFactory::makeCommand(const std::vector<std::string> &args)
{
    validateArgs(args);
    auto command = std::make_unique<RemoveCommand>();
    command->setArguments(args);
    return command;
}

std::unique_ptr<CommandFactory> RemoveFactory::clone() const
{
    return std::make_unique<RemoveFactory>();
}

void RemoveFactory::validateArgs(const std::vector<std::string> &args)
{
    if(validOptions.find(*args.begin()) == validOptions.end()){
        throw std::runtime_error("to remove item write -id [Item id]");
    }
}
