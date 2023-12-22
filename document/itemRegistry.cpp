#include "itemRegistry.hpp"

ItemRegistry::ItemRegistry()
{
    m_registry["Rect"] = Item::Item_tag::RECT;
    m_registry["Ellipse"] = Item::Item_tag::ELLIPSE;
    m_registry["Text"] = Item::Item_tag::TEXT;
}

Item::Item_tag ItemRegistry::findItem(const std::string &itemName)
{
    auto itemIter = m_registry.find(itemName);    
    if(itemIter == m_registry.end()){
        throw std::runtime_error("not such a item "+ itemName);
    }
    return itemIter->second;
}
