#include "Rect.hpp"
#include "../serializer/iSerializer.hpp"


Rect::Rect()
{
    itemOptions.insert("-x1");
    itemOptions.insert("-x2");
    itemOptions.insert("-y1");
    itemOptions.insert("-y2");
}

std::string Rect::type()
{
    return std::string("Rect");
}

std::string Rect::info()
{
    std::string objInfo = type() + " " + m_topLeft.info() + " " + m_bottomRight.info();
    return objInfo;
}

Item::Item_tag Rect::tag()
{
    return Item_tag::RECT;
}

void Rect::accept(iSerializer &vi)
{
    auto rect_tag = tag();
    vi.visit(rect_tag);
    vi.visit(m_topLeft);
    vi.visit(m_bottomRight);
}

Point Rect::getTopLeft()
{
    return m_topLeft;
}

Point Rect::getBottomRight()
{
    return m_bottomRight;
}

void Rect::setAttribute(std::string key, std::variant<std::string,double,int> value)
{
    if(key == "-x1"){
        m_topLeft.setX(std::get<double>(value));
    }
    if(key == "-y1"){
        m_topLeft.setY(std::get<double>(value));
    }
    if(key == "-x2"){
        m_bottomRight.setX(std::get<double>(value));
    }
    if(key == "-y2"){
        m_bottomRight.setY(std::get<double>(value));
    }
}

std::unique_ptr<Item> Rect::clone()
{
    return std::make_unique<Rect>();
}
