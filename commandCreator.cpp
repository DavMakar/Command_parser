#include "commandCreator.hpp"

std::unique_ptr<Command> CommandCreator::createCommand(const std::string &commandName, const std::vector<std::string> &args)
{
    auto commandFactory = factoryRegistry_.findFactory(commandName);
    return commandFactory->makeCommand(args);
}
