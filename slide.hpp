#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <unordered_map>
#include <vector>
#include "item.hpp"

using ItemStore = std::unordered_map<int , std::unique_ptr<Item>>;

class Slide{
public:
    void addItem(std::unique_ptr<Item>);
    void changeItem(int id);
    void removeItem(int id);
    std::string getAllItems();
    std::string getItemById(int id);

    // ItemStore::iterator begin() ;
    // ItemStore::iterator end();
    ItemStore::const_iterator begin() const;
    ItemStore::const_iterator end() const;
    ItemStore::const_iterator cbegin() const;
    ItemStore::const_iterator cend() const;

private:
    ItemStore::iterator findItem(int id);
private:
    int id_ = 0;
    ItemStore items_;
};

#endif //SLIDE_HPP
