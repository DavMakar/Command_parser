#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "item.hpp"

class Ellipse : public Item{
public:
    std::string type() override;
    std::string info() override;
    Item::Item_tag tag() override;
    void accept(iSerializer& vi) override;
    void setAttribute(std::string key , std::variant<std::string,double,int> value) override;
    std::unique_ptr<Item> clone() override;
};

#endif //ELLIPSE_HPP
