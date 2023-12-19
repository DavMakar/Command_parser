#include "ShapeText.hpp"
#include "../document/item.hpp"
#include "../document/Text.hpp"
#include <QPainter>
#include <QString>

void ShapeText::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    auto textItem = std::dynamic_pointer_cast<Text>(item);
    QFont font = painter->font();
    font.setPixelSize(textItem->getSize());
    painter->setFont(font);
    painter->drawText(textItem->getBoundingBox(), QString::fromStdString(textItem->getContent()));
}

