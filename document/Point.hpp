#ifndef POINT_HPP
#define POINT_HPP

#include "item.hpp"
class Visitor;

class Point : public Item{
public:
    Point() = default;
    Point(double x, double y);
    void accept(Visitor& vi) override;
    void setX(double x);
    void setY(double y);
    std::string info() override;
    std::string type() override;
private:
    double x_;
    double y_;
};

#endif //POINT_HPP