#ifndef TEXT_ITEM_HPP
#define TEXT_ITEM_HPP

#include "item.hpp"
#include "Point.hpp"

class Text : public Item{
public:
    std::string type() override;
    std::string info() override;
    Item::Item_tag tag() override;
    void accept(iSerializer& ) override;
    void setAttribute(std::string key , std::variant<std::string,double,int> value) override;
    std::unique_ptr<Item> clone() override;
    
    std::string getContent();
private:
    std::string content;
};

#endif //TEXT_ITEM_HPP