#include "itemRegistry.hpp"
#include "Rect.hpp"

ItemRegistry::ItemRegistry()
{
    registerItems();
}

void ItemRegistry::registerItems(){
    registry_["Rect"] = std::make_unique<Rect>();
    //registry_["Cycle"] = std::make_unique<Item>();
}

std::unique_ptr<Item> ItemRegistry::findItem(std::string itemName)
{
    auto itemIter = registry_.find(itemName);    
    if(itemIter == registry_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return itemIter->second->clone();
}
