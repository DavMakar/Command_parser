#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <stdexcept>
#include <any>

class Visitor;

class Item
{ 
using Options = std::unordered_set<std::string>;
public:
    enum class Item_tag : size_t { Rect};    
    Item();
    virtual ~Item();
    int getId();
    Options& getOptions();
    
    virtual void accept(Visitor& vi) = 0;
    virtual std::string type() = 0;
    virtual std::string info() = 0;
    virtual Item_tag tag() = 0;
    virtual void setAttribute(std::string key , std::any value) = 0;
    virtual std::unique_ptr<Item> clone() = 0;  

protected:
    Options itemOptions;
private:
    int id_;
    static int counter;
};


#endif //ITEM_HPP