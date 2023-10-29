#ifndef ITEM_REGISTRY_HPP
#define ITEM_REGISTRY_HPP

#include  "item.hpp"
#include <unordered_map>

class ItemRegistry{

using Register = std::unordered_map<std::string,std::unique_ptr<Item>>; 
public:
    ItemRegistry();
    void registerItem(const std::string& itemName, std::unique_ptr<Item> entry);
    std::unique_ptr<Item> findItem(const std::string& itemName);
private:
    Register registry_;
};

#endif //ITEM_REGISTRY_HPP
