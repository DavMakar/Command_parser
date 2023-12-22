#include "ShapeText.hpp"
#include "../document/item.hpp"
#include "../document/TextAttributes.hpp"
#include <QPainter>
#include <QString>

void ShapeText::draw(QPainter *painter, std::shared_ptr<Item> item)
{
    QFont font = painter->font();
    font.setPixelSize(item->getTextAttributes().getSize());
    painter->setFont(font);
    painter->drawText(item->getBoundingBox(), QString::fromStdString(item->getTextAttributes().getText()));
}

