#ifndef SHAPE_ELLIPSE_HPP
#define SHAPE_ELLIPSE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class ShapeEllipse : public ShapeBase , public IVisualDisplayable{
    void draw(QPainter* painter, std::shared_ptr<Item> item) override;
};

#endif //SHAPE_ELLIPSE_HPP
