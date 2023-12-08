#include "ShapeRect.hpp"

#include <QRectF>
#include <QPainter>
#include "../document/item.hpp"
#include "../document/Rect.hpp"

void ShapeRect::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    auto rect = std::dynamic_pointer_cast<Rect>(item);
    QPointF topLeft = QPointF(rect->getTopLeft().x(),rect->getTopLeft().y());
    QPointF bottomRight = QPointF(rect->getBottomRight().x(),rect->getBottomRight().y());
    QRectF qrect(topLeft,bottomRight);

    painter->drawRect(qrect);
}