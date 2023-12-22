#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <unordered_map>
#include <vector>
#include <ostream>
#include "item.hpp"

using ItemStore = std::vector<std::shared_ptr<Item>>;

class Slide{
public:
    Slide();
    void accept(iSerializer& vi);
    size_t addItem(std::shared_ptr<Item>);
    void removeItem(size_t id);
    void changeItem(size_t id);
    size_t getItemCount(); 
    //void accept(SerializeriSerializer& sv);
    //void accept(DeserializeriSerializer& dv);

    std::string getAllItems();
    std::shared_ptr<Item> getItemById(int id);
    
    ItemStore::iterator begin();
    ItemStore::iterator end();
    ItemStore::const_iterator begin() const;
    ItemStore::const_iterator end() const;
    ItemStore::const_iterator cbegin() const;
    ItemStore::const_iterator cend() const;

private:
    ItemStore::iterator findItem(int id);
private:
    size_t m_itemCount = 0;
    ItemStore m_items;
};

#endif //SLIDE_HPP
