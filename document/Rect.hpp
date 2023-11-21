#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "item.hpp"
#include "Point.hpp"
#include <unordered_set>

class Visitor;

class Rect: public Item{
public:
    Rect();
    std::string type() override;
    std::string info() override;
    Item::Item_tag tag() override;
    void accept(Visitor& vi) override;
    void setAttribute(std::string key , std::string value) override;
    std::unique_ptr<Item> clone() override;
private:
    Point p1;
    Point p2;
};

#endif //RECTANGLE_HPP
