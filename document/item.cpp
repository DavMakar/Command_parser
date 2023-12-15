#include "item.hpp"

Item::Options Item::getOptions() const
{
    return m_itemOptions;
}

void Item::setPenStyle(PenStyle penStyle)
{
    m_penStyle = penStyle;
}

void Item::setOptions(Options options)
{
    m_itemOptions = options;  
}

void Item::setBoundingBox(BoundingBox box)
{
    m_box = box;
}

BoundingBox Item::getBoundingBox() const
{
    return m_box;
}

PenStyle Item::getPenStyle() const
{
    return m_penStyle;
}
