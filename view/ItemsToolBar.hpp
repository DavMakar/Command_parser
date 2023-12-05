#ifndef ITEMSTOOLBAR_HPP
#define ITEMSTOOLBAR_HPP

#include <QToolBar>

class ItemsToolBar : public QToolBar
{
    Q_OBJECT
public:
    ItemsToolBar(QToolBar* parent = nullptr);
};

#endif // ITEMSTOOLBAR_HPP
