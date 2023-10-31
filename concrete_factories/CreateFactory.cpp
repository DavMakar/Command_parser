#include "CreateFactory.hpp"
#include "../concrete_commands/CreateCommand.hpp"

std::unique_ptr<Command> CreateFactory::makeCommand(const std::vector<std::string> &args)
{
    validateArgs(args);

    auto command = std::make_unique<CreateCommand>();
    command->setArguments(args);
    return command;
}

void CreateFactory::validateArgs(const std::vector<std::string> &args)
{
    if(validOptions.find(*args.begin()) == validOptions.end()){
        throw std::runtime_error("to create slide write -slide");
    }
}

std::unique_ptr<CommandFactory> CreateFactory::clone() const{
    return std::make_unique<CreateFactory>();
}