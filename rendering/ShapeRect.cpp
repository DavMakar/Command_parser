#include "ShapeRect.hpp"

#include <QRectF>
#include <QPainter>
#include "../document/item.hpp"

void ShapeRect::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    painter->drawRect(item->getBoundingBox());
}
