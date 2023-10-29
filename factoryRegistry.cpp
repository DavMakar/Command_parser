#include "factoryRegistry.hpp"

#include "concrete_factories/AddFactory.hpp"
#include "concrete_factories/DisplayFactory.hpp"
#include "concrete_factories/ListFactory.hpp"
#include "concrete_factories/LoadFactory.hpp"
#include "concrete_factories/QuitFactory.hpp"
#include "concrete_factories/RemoveFactory.hpp"
#include "concrete_factories/SaveFactory.hpp"

FactoryRegistry::FactoryRegistry()
{
    registerFactory("add",std::make_unique<AddFactory>());
    registerFactory("display",std::make_unique<DisplayFactory>());
    registerFactory("list",std::make_unique<ListFactory>());
    registerFactory("load",std::make_unique<LoadFactory>());
    registerFactory("quit",std::make_unique<QuitFactory>());
    registerFactory("remove",std::make_unique<RemoveFactory>());
    registerFactory("save",std::make_unique<SaveFactory>());
}

std::unique_ptr<CommandFactory> FactoryRegistry::findFactory(const std::string& factoryName)
{
    auto factoryIter = registry_.find(factoryName);    
    if(factoryIter == registry_.end()){
        throw std::runtime_error("not such a factory "+ factoryName);
    }
    return factoryIter->second->clone();
}

void FactoryRegistry::registerFactory(const std::string &factoryName, std::unique_ptr<CommandFactory> factory)
{
    registry_[factoryName] = std::move(factory);
}
