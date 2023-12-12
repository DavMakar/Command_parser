#include "ShapeRect.hpp"

#include <QRectF>
#include <QPainter>
#include "../document/item.hpp"
#include "../document/Rect.hpp"

void ShapeRect::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    auto rect = std::dynamic_pointer_cast<Rect>(item);
    QRectF qrect(rect->getTopLeft(),rect->getBottomRight());
    painter->drawRect(qrect);
}