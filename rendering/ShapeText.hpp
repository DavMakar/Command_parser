#ifndef SHAPE_TEXT_HPP
#define SHAPE_TEXT_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class ShapeText : public ShapeBase , public IVisualDisplayable{
    void draw(QPainter* painter, std::shared_ptr<Item> item) override;
};

#endif //SHAPE_TEXT_HPP