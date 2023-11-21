#include "Rect.hpp"
#include "../serializer/Visitor.hpp"

Rect::Rect()
{
    validArguments.insert("-x1");
    validArguments.insert("-y1");
    validArguments.insert("-x2");
    validArguments.insert("-y2");
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

// std::string Rect::getAttrbute(std::string key)
// {
//     return attributes_[key];
// }

void Rect::setAttribute(std::string key, std::string value)
{
    if(key == "-x1"){
        p1.setX(std::stod(value));
    }
    if(key == "-y1"){
        p1.setY(std::stod(value));
    }
    if(key == "-x2"){
        p2.setX(std::stod(value));
    }
    if(key == "-y2"){
        p2.setY(std::stod(value));
    }
}

std::unique_ptr<Item> Rect::clone()
{
    return std::make_unique<Rect>();
}
