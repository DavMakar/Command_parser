#ifndef ITEM_REGISTRY_HPP
#define ITEM_REGISTRY_HPP

#include <unordered_map>
#include <unordered_set>
#include "item.hpp"

class ItemRegistry{

using Register = std::unordered_map<std::string, Item::Item_tag>; 
public:
    ItemRegistry();
    Item::Item_tag findItem(const std::string& itemName);
private:
    Register m_registry;
};

#endif //ITEM_REGISTRY_HPP
