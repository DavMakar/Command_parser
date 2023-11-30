#include "Point.hpp"
#include "../serializer/Visitor.hpp"

Point::Point(double x, double y)
    :x_(x),y_(y)
{
}

void Point::setX(double x)
{
    x_ = x;
}

void Point::setY(double y)
{
    y_ = y;
}

void Point::accept(Visitor &vi)
{
    vi.visit(x_);
    vi.visit(y_);
}

std::string Point::info()
{
    std::string info = type() + " " + std::to_string(x_) + " " + std::to_string(y_);
    return info;
}

std::string Point::type()
{
    return std::string("Point");
}
