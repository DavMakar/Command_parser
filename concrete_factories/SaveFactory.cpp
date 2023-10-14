#include "SaveFactory.hpp"
#include "../concrete_commands/SaveCommand.hpp"

std::unique_ptr<Command> SaveFactory::makeCommand(const std::vector<std::string> &args)
{
    auto command = std::make_unique<SaveCommand>();
    command->setArguments(args);
    return command;
}

std::unique_ptr<CommandFactory> SaveFactory::clone() const
{
    return std::make_unique<SaveFactory>();
}

void SaveFactory::validateArgs(const std::vector<std::string> &args)
{
    if(validOptions.find(*args.begin()) == validOptions.end()){
        throw std::runtime_error("write -file [path]");
    }
}
