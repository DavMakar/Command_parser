#include "PenAttributesConverter.hpp"
#include "../document/PenAttributes.hpp"

QPen PenAttributesConverter::toQPen(const PenAttributes& penAttributes)
{
    QPen pen;
    pen.setColor(toQColor(penAttributes.getColor()));
    pen.setStyle(toQtPenStyle(penAttributes.getStyle()));
    pen.setWidth(penAttributes.getWidth());
    return pen;
}

QColor PenAttributesConverter::toQColor(const std::string &color)
{
    return QColor::fromString(color);
}

Qt::PenStyle PenAttributesConverter::toQtPenStyle(const std::string &style)
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
