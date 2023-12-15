#ifndef PEN_STYLE_HPP
#define PEN_STYLE_HPP

#include <string>
#include <map>
#include <QPen>

class PenStyle{
public:
    PenStyle() = default;
    PenStyle(const std::string& color, const std::string& style , int width);
    std::string getColor() const;
    std::string getStyle() const;
    int getWidth() const;

private:
    std::string m_style;
    std::string m_color;
    int m_width;
};

#endif //PEN_STYLE_HPP
