#ifndef PEN_STYLE_CONVERTER_HPP
#define PEN_STYLE_CONVERTER_HPP

#include <QPen>
#include <QColor>

class PenStyle;

class PenStyleConverter{
public:
    QPen toQPen(const PenStyle& penStyle);
private:
    QColor toQColor(const std::string& color);
    Qt::PenStyle toQtPenStyle(const std::string& style);
};

#endif //PEN_STYLE_CONVERTER_HPP