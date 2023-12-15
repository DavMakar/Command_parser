#include "ShapeEllipse.hpp"

#include <QRectF>
#include <QPainter>
#include "../document/Ellipse.hpp"

void ShapeEllipse::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    auto ellipseItem = std::dynamic_pointer_cast<Ellipse>(item);
    painter->drawEllipse(ellipseItem->getBoundingBox());
}