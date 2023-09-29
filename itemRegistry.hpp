#ifndef ITEM_REGISTRY_HPP
#define ITEM_REGISTRY_HPP

#include "item.hpp"
#include <unordered_map>
#include <memory>
#include <string>

class ItemRegistry
{
using Register = std::unordered_map<std::string, std::unique_ptr<Item>>;

public:
    ItemRegistry();

    std::unique_ptr<Item> findItem(std::string itemName);
private:
    void registerItems();
    Register registry_;
};

#endif // ITEM_REGISTRY_HPP