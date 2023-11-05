#include "QuitFactory.hpp"
#include "../commands/QuitCommand.hpp"

std::unique_ptr<Command> QuitFactory::makeCommand(const std::vector<std::string> &args)
{
    auto command = std::make_unique<QuitCommand>();
    command->setArguments(args);
    return command;
}


std::unique_ptr<CommandFactory> QuitFactory::clone() const
{
    return std::make_unique<QuitFactory>();
}

void QuitFactory::validateArgs(const std::vector<std::string> &args)
{
}
