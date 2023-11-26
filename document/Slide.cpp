#include "Slide.hpp"
#include "../serializer/Visitor.hpp"

Slide::Slide()
{
}

void Slide::addItem(std::unique_ptr<Item> new_item)
{
    items_[itemId++] = std::move(new_item);
    ++itemCount;
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

void Slide::accept(Visitor &vi)
{
    std::string type("Slide");
    vi.visit(type);
    vi.visit(itemCount);

    if(items_.empty()){
        for(size_t i = 0 ; i < itemCount ; ++i){
            Item::Item_tag tag;       
            vi.visit(tag);
            items_[i]= std::move(vi.make_item(tag));
            vi.visit(items_[i]);
        }
    }else{
        for(auto& [id , item] : items_){
            vi.visit(item);
        }
    }
}

std::string Slide::getAllItems()
{
    std::string result;
    for(const auto& [id , item] : items_){
        result += std::to_string(id) + " " + item->type() + "\n";
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
