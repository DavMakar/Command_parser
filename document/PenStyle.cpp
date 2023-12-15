#include "PenStyle.hpp"

PenStyle::PenStyle(const std::string &color, const std::string &style, int width)
    :m_color(color) , m_style(style), m_width(width)
{
}

std::string PenStyle::getColor() const
{
    return m_color;
}

std::string PenStyle::getStyle() const
{
    return m_style;
}

int PenStyle::getWidth() const
{
    return m_width;
}
