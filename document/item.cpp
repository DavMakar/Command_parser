#include "item.hpp"


int Item::counter = 0;

Item::Item(Item::Item_tag tag, BoundingBox box, PenAttributes penAttr, TextAttributes textAttr)
    :m_id(++counter) ,
     m_tag(tag),
     m_box(box) , 
     m_penAttributes(penAttr) ,
     m_textAttributes(textAttr)
{
}

void Item::setPenAttributes(PenAttributes penAttr)
{
    m_penAttributes = penAttr;
}

void Item::setTextAttributes(TextAttributes textAttributes)
{
    m_textAttributes = textAttributes;
}

void Item::setBoundingBox(BoundingBox box)
{
    m_box = box;
}

void Item::accept(iSerializer &vi)
{
    //
}

Item::Item_tag Item::tag()
{
    return m_tag;
}

std::string Item::info()
{
    return std::string();
}

std::string Item::type()
{
    switch (m_tag){
        case Item_tag::RECT:
            return std::string("Rect");
        case Item_tag::ELLIPSE:
            return std::string("Ellipse");
        case Item_tag::TEXT:
            return std::string("Text");
        case Item_tag::CIRCLE:
            return std::string("Circle");
    }
    return std::string();
}

BoundingBox Item::getBoundingBox() const
{
    return m_box;
}

PenAttributes Item::getPenAttributes() const
{
    return m_penAttributes;
}

int Item::getId()
{
    return m_id;
}

TextAttributes Item::getTextAttributes() const
{
    return m_textAttributes;
}
