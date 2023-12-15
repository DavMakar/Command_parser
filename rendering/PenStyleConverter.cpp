#include "PenStyleConverter.hpp"
#include "../document/PenStyle.hpp"

QPen PenStyleConverter::toQPen(const PenStyle& penStyle)
{
    QPen pen;
    pen.setColor(toQColor(penStyle.getColor()));
    pen.setStyle(toQtPenStyle(penStyle.getStyle()));
    pen.setWidth(penStyle.getWidth());
    return pen;
}

QColor PenStyleConverter::toQColor(const std::string &color)
{
    return QColor::fromString(color);
}

Qt::PenStyle PenStyleConverter::toQtPenStyle(const std::string &style)
{
    if(style == "DotLine"){
        return Qt::PenStyle::DotLine;
    }
    if(style == "DashLine"){
        return Qt::PenStyle::DashLine;
    }
    if(style == "SolidLine"){
        return Qt::PenStyle::SolidLine;
    }
}
