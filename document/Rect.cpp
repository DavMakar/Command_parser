#include "Rect.hpp"
#include "../serializer/iSerializer.hpp"

std::string Rect::type()
{
    return std::string("Rect");
}

std::string Rect::info()
{
    std::string objInfo = type();// + " " + m_box.info();
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
    vi.visit(m_box);
    //vi.visit(m_penStyle);
}

void Rect::setAttribute(std::string key, std::variant<std::string,double,int> value)
{
}

std::unique_ptr<Item> Rect::clone()
{
    return std::make_unique<Rect>();
}
