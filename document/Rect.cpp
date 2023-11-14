#include "Rect.hpp"
#include "Visitor.hpp"

Rect::Rect()
{
    validArguments.insert("-x1");
    validArguments.insert("-y1");
    validArguments.insert("-x2");
    validArguments.insert("-y2");
}

Rect::Rect(Point p1, Point p2)
    :p1_(p1), p2_(p2)
{
}

void Rect::accept(Visitor& vi){
    vi.visit(p1_);
    vi.visit(p2_);
}

std::string Rect::type()
{
    return std::string("Rect");
}

std::string Rect::info()
{
    std::string objInfo = type() + " " + p1_.info() +" "+ p2_.info();
    return objInfo;
}

// void Rect::setAttribute(std::string key, std::string value)
// {
//     if(key == "-x1"){
//         p1.setX(std::stod(value));
//     } 
//     if(key == "-y1"){
//         p1.setY(std::stod(value));
//     }
//     if(key == "-x2"){
//         p2.setX(std::stod(value));
//     }
//     if(key == "-y2"){
//         p2.setY(std::stod(value));
//     }
// }
