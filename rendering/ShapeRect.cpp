#include "ShapeRect.hpp"

#include <QRectF>
#include <QPainter>
#include "../document/item.hpp"
#include "../document/Rect.hpp"

void ShapeRect::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    auto rectItem = std::dynamic_pointer_cast<Rect>(item);
    painter->drawRect(rectItem->getBoundingBox());
}