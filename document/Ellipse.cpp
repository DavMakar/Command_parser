#include "Ellipse.hpp"

std::string Ellipse::type()
{
    return std::string("Ellipse");
}

std::string Ellipse::info(){
    std::string objInfo = type();// + " " + m_box.info();
    return objInfo;
}

Item::Item_tag Ellipse::tag(){
    return Item_tag::ELLIPSE;
}

void Ellipse::accept(iSerializer& vi){
    //
}

void Ellipse::setAttribute(std::string key, std::variant<std::string, double, int> value){
    //
}

std::unique_ptr<Item> Ellipse::clone(){
    return std::make_unique<Ellipse>();
}
