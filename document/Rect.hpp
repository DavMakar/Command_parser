#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "item.hpp"
#include "Point.hpp"
#include <unordered_set>

class iSerializer;

class Rect: public Item{
public:
    Rect();
    std::string type() override;
    std::string info() override;
    Item::Item_tag tag() override;
    void accept(iSerializer& vi) override;
    Point getTopLeft();
    Point getBottomRight();
    void setAttribute(std::string key , std::any value) override;
    std::unique_ptr<Item> clone() override;
private:
    Point m_topLeft;
    Point m_bottomRight;
};

#endif //RECTANGLE_HPP
