#include "Point.hpp"
#include "../serializer/iSerializer.hpp"

Point::Point(double x, double y)
    :m_x(x),m_y(y)
{
}

void Point::setX(double x)
{
    m_x = x;
}

void Point::setY(double y)
{
    m_y = y;
}

double Point::x()
{
    return m_x;
}

double Point::y()
{
    return m_y;
}

void Point::accept(iSerializer &vi)
{
    vi.visit(m_x);
    vi.visit(m_y);
}

std::string Point::info()
{
    std::string info = type() + " " + std::to_string(m_x) + " " + std::to_string(m_y);
    return info;
}

std::string Point::type()
{
    return std::string("Point");
}
