#ifndef PEN_ATTRIBUTES_HPP
#define PEN_ATTRIBUTES_HPP

#include <string>
#include <map>
#include <QPen>

class PenAttributes{
public:
    PenAttributes() = default;
    PenAttributes(const std::string& color, const std::string& style , int width);
    std::string getColor() const;
    std::string getStyle() const;
    int getWidth() const;

private:
    std::string m_style;
    std::string m_color;
    int m_width;
};

#endif //PEN_ATTRIBUTES_HPP
