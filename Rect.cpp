#include "Rect.hpp"

Rect::Rect()
{
    validArguments.insert("-x1");
    validArguments.insert("-y1");
    validArguments.insert("-x2");
    validArguments.insert("-y2");
}

std::string Rect::className()
{
    return std::string("Rect ");
}

std::string Rect::info()
{
    std::string objInfo = className();
    for(const auto& [key , value] : attributes_){
        objInfo += key + " " + value + " ";
    }
    return objInfo;
}

std::string Rect::getAttrbute(std::string key)
{
    return attributes_[key];
}

void Rect::setAttribute(std::string key, std::string value)
{
    attributes_[key] = value;
}

std::unique_ptr<Item> Rect::clone()
{
    return std::make_unique<Rect>(*this);
}
