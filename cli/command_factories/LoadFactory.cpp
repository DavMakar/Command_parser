#include "LoadFactory.hpp"
#include "../commands/LoadCommand.hpp"

std::unique_ptr<Command> LoadFactory::makeCommand(const std::vector<std::string> &args)
{
    validateArgs(args);

    auto command = std::make_unique<LoadCommand>();
    command->setArguments(args);
    return command;
}

void LoadFactory::validateArgs(const std::vector<std::string>& args)
{
    if(validOptions.find(*args.begin()) == validOptions.end()){
        throw std::runtime_error("write -file [path]");
    }
}

std::unique_ptr<CommandFactory> LoadFactory::clone() const{
    return std::make_unique<LoadFactory>();
}