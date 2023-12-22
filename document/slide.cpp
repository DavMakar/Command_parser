#include "slide.hpp"
#include "../serializer/iSerializer.hpp"
#include <QDebug>

Slide::Slide()
{
}

size_t Slide::addItem(std::shared_ptr<Item> new_item)
{
    auto id = new_item->getId();
    m_items.push_back(new_item);
    return id;
}

void Slide::changeItem(size_t id)
{
    auto item = findItem(id);
}

size_t Slide::getItemCount()
{
    return m_itemCount;
}

void Slide::removeItem(size_t id)
{
    m_items.erase(findItem(id));
}

void Slide::accept(iSerializer &vi)
{
    std::string type("Slide");
    vi.visit(type);
    vi.visit(m_itemCount);

    if(m_items.empty()){
        for(size_t i = 0 ; i < m_itemCount ; ++i){
            Item::Item_tag tag;       
            vi.visit(tag);
            m_items[i]= std::move(vi.make_item(tag));
            vi.visit(m_items[i]);
        }
    }else{
        for(auto& item : m_items){
            vi.visit(item);
        }
    }
}

std::string Slide::getAllItems()
{
    std::string result;
    for(const auto& item : m_items){
        result += std::to_string(item->getId()) + " " + item->type() + "\n";
    }
    return result;
}

std::shared_ptr<Item> Slide::getItemById(int id)
{
    auto it = findItem(id);
    return *it;
}

ItemStore::iterator Slide::begin()
{
    return m_items.begin();
}
ItemStore::iterator Slide::end()
{
    return m_items.end();
}

ItemStore::const_iterator Slide::cbegin() const
{
    return m_items.cbegin();
}

ItemStore::const_iterator Slide::cend() const{
    return m_items.cend();
}

ItemStore::const_iterator Slide::begin() const
{
    return ItemStore::const_iterator(m_items.begin());
}

ItemStore::const_iterator Slide::end() const
{
    return ItemStore::const_iterator(m_items.end());
}

ItemStore::iterator Slide::findItem(int id)
{
    auto it = std::find_if(m_items.begin(),m_items.end(), [=](auto item){
                return item->getId() == id;
              });
              
    if(it == m_items.end()){
        throw std::runtime_error("item not found");
    }
    return it;
}  
