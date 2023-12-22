#ifndef PEN_STYLE_CONVERTER_HPP
#define PEN_STYLE_CONVERTER_HPP

#include <QPen>
#include <QColor>

class PenAttributes;

class PenAttributesConverter{
public:
    QPen toQPen(const PenAttributes& penAttr);
private:
    QColor toQColor(const std::string& color);
    Qt::PenStyle toQtPenStyle(const std::string& style);
};

#endif //PEN_STYLE_CONVERTER_HPP