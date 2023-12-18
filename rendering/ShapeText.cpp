#include "ShapeText.hpp"
#include "../document/item.hpp"
#include "../document/Text.hpp"
#include <QPainter>
#include <QString>

void ShapeText::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    auto textItem = std::dynamic_pointer_cast<Text>(item);
    painter->setFont(QFont("Times", 25, QFont::Normal));
    painter->drawText(textItem->getBoundingBox(), Qt::AlignCenter, QString::fromStdString(textItem->getContent()));
}
