#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "item.hpp"
#include "Point.hpp"
#include <unordered_set>

class Visitor;

class Rect: public Item{
public:
    Rect();
    Rect(Point p1, Point p2);
    std::string type() override;
    std::string info() override;
    void accept(Visitor& vi) override;

private:
    Point p1_;
    Point p2_;
};

#endif //RECTANGLE_HPP
