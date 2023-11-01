#include "slide.hpp"

void Slide::addItem(std::unique_ptr<Item> new_item)
{
    items_[item_id++] = std::move(new_item);
}

void Slide::changeItem(int id)
{
    auto item = findItem(id);
}

void Slide::removeItem(int id)
{
    auto item = findItem(id);
    items_.erase(item);
    //items.erase(item[id]);
}

std::string Slide::getAllItems()
{
    std::string result;
    for(const auto& [id , item] : items_){
        result += id + " " + item->type() + "\n";
    }
    return result;
}

std::shared_ptr<Item> Slide::getItemById(int id)
{
    auto item = findItem(id);
    return item->second;
}

// ItemStore::iterator Slide::begin()
// {
//     return items_.begin();
// }
// ItemStore::iterator Slide::end() 
// {
//     return items_.end();
// }
ItemStore::const_iterator Slide::cbegin() const
{
    return items_.cbegin();
}

ItemStore::const_iterator Slide::cend() const{
    return items_.cend();
}

ItemStore::const_iterator Slide::begin() const
{
    return ItemStore::const_iterator(items_.begin());
}

ItemStore::const_iterator Slide::end() const
{
    return ItemStore::const_iterator(items_.end());
}

ItemStore::iterator Slide::findItem(int id)
{
    auto item =  items_.find(id);
    if(item == items_.end()){
        throw std::runtime_error("item not found");
    }
    return item;
}  
