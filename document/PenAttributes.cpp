#include "PenAttributes.hpp"

PenAttributes::PenAttributes(const std::string &color, const std::string &style, int width)
    :m_color(color) , m_style(style), m_width(width)
{
}

std::string PenAttributes::getColor() const
{
    return m_color;
}

std::string PenAttributes::getStyle() const
{
    return m_style;
}

int PenAttributes::getWidth() const
{
    return m_width;
}
