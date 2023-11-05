#include "ListFactory.hpp"
#include "../commands/ListCommand.hpp"

std::unique_ptr<Command> ListFactory::makeCommand(const std::vector<std::string> &args)
{
    auto command = std::make_unique<ListCommand>();
    command->setArguments(args);
    return command;
}

std::unique_ptr<CommandFactory> ListFactory::clone() const
{
    return std::make_unique<ListFactory>();
}

void ListFactory::validateArgs(const std::vector<std::string> &args)
{
}
