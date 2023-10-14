#include "commandCreator.hpp"

#include "concrete_factories/AddFactory.hpp"
#include "concrete_factories/DisplayFactory.hpp"
#include "concrete_factories/ListFactory.hpp"
#include "concrete_factories/LoadFactory.hpp"
#include "concrete_factories/QuitFactory.hpp"
#include "concrete_factories/RemoveFactory.hpp"
#include "concrete_factories/SaveFactory.hpp"

CommandCreator::CommandCreator()
{
    factoryRegistry_.registerEntry("add",std::make_unique<AddFactory>());
    factoryRegistry_.registerEntry("display",std::make_unique<DisplayFactory>());
    factoryRegistry_.registerEntry("list",std::make_unique<ListFactory>());
    factoryRegistry_.registerEntry("load",std::make_unique<LoadFactory>());
    factoryRegistry_.registerEntry("quit",std::make_unique<QuitFactory>());
    factoryRegistry_.registerEntry("remove",std::make_unique<RemoveFactory>());
    factoryRegistry_.registerEntry("save",std::make_unique<SaveFactory>());
}

std::unique_ptr<Command> CommandCreator::createCommand(const std::string &commandName, const std::vector<std::string> &args)
{
    auto commandFactory = factoryRegistry_.findEntry(commandName);
    return commandFactory->makeCommand(args);
}
