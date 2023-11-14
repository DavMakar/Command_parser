#include "itemRegistry.hpp"
#include "Rect.hpp"
#include "Point.hpp"

ItemRegistry::ItemRegistry()
{
    registerItem("Rect", std::make_unique<Rect>());
    registerItem("Point", std::make_unique<Point>());
}

void ItemRegistry::registerItem(const std::string &itemName, std::unique_ptr<Item> item)
{
    registry_[itemName] = std::move(item);
}

std::unique_ptr<Item> ItemRegistry::findItem(const std::string &itemName)
{
    auto itemIter = registry_.find(itemName);    
    if(itemIter == registry_.end()){
        throw std::runtime_error("not such a item "+ itemName);
    }
    return itemIter->second->clone();
}