#ifndef SHAPE_RECT_HPP
#define SHAPE_RECT_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class ShapeRect : public ShapeBase , public IVisualDisplayable{
    void draw(QPainter* painter, std::shared_ptr<Item> item) override;
};

#endif //SHAPE_RECT_HPP
