#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <stdexcept>
#include <variant>

class iSerializer;

class Item
{ 
using Options = std::unordered_set<std::string>;
public:
    enum class Item_tag : size_t { Rect , Text , Circle};    
    virtual ~Item() = default;
    Options& getOptions();
    
    virtual void accept(iSerializer& vi) = 0;
    virtual std::string type() = 0;
    virtual std::string info() = 0;
    virtual Item_tag tag() = 0;
    virtual void setAttribute(std::string key , std::variant<std::string,double,int> value) = 0;
    virtual std::unique_ptr<Item> clone() = 0;  

protected:
    Options itemOptions;
};


#endif //ITEM_HPP
