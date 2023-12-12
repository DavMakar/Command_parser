#include "ItemsToolBar.hpp"

#include <QPixmap>

ItemsToolBar::ItemsToolBar(QToolBar* parent)
    :QToolBar(parent)
{
    addAction(QPixmap(":/items/item_icons/rect.png"), "1");
    addAction(QPixmap(":/items/item_icons/circle.png"), "2");
    addAction(QPixmap(":/items/item_icons/line.png"), "3");
    addAction(QPixmap(":/items/item_icons/text.png"), "4");
}
