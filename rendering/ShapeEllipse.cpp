#include "ShapeEllipse.hpp"

#include "../document/item.hpp"
#include <QRectF>
#include <QPainter>

void ShapeEllipse::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    painter->drawEllipse(item->getBoundingBox());
}
