#include "Visitor.hpp"
#include "Rect.hpp"
#include "Point.hpp"

std::unique_ptr<Item> Visitor::makeShape(std::string& type){
    if(type != "Rect"){
        throw std::runtime_error("valid type [Rect]");
    }
    return std::make_unique<Rect>();
}