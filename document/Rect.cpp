#include "Rect.hpp"
#include "../serializer/Visitor.hpp"

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
    std::string objInfo = type() + " " + p1.info() + " " + p2.info();
    return objInfo;
}

Item::Item_tag Rect::tag()
{
    return Item_tag::Rect;
}

void Rect::accept(Visitor &vi)
{
    auto rect_tag = tag();
    vi.visit(rect_tag);
    vi.visit(p1);
    vi.visit(p2);
}

void Rect::setAttribute(std::string key, std::any value)
{
    if(key == "-x1"){
        p1.setX(std::any_cast<double>(value));
    }
    if(key == "-y1"){
        p1.setY(std::any_cast<double>(value));
    }
    if(key == "-x2"){
        p2.setX(std::any_cast<double>(value));
    }
    if(key == "-y2"){
        p2.setY(std::any_cast<double>(value));
    }
}

std::unique_ptr<Item> Rect::clone()
{
    return std::make_unique<Rect>();
}
