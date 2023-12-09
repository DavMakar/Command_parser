#ifndef SHAPE_LIBRARY_HPP
#define SHAPE_LIBRARY_HPP

#include "../document/item.hpp"
#include "ShapeBase.hpp"
#include <unordered_map>

class ShapeLibrary{
public:
    ShapeLibrary();
    std::shared_ptr<ShapeBase> getShape(Item::Item_tag);
private:
    std::unordered_map<Item::Item_tag , std::shared_ptr<ShapeBase>> m_lib;
};


#endif //SHAPE_LIBRARY_HPP
