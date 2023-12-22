#include "Renderer.hpp"
#include "../document/Slide.hpp"
#include "../document/item.hpp"
#include "IVisualDisplayable.hpp"
#include "PenAttributesConverter.hpp"
#include <QPainter>


void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice)
{
    QPainter painter;
    painter.begin(paintDevice);
    PenAttributesConverter penAttrConverter;
    //auto item = slide->getTopItem();

    for(auto item : *slide){
        painter.setPen(penAttrConverter.toQPen(item->getPenAttributes()));
        std::shared_ptr<IShape> shape = m_shapeLibrary.getShape(item->tag());
        auto ivd = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
        assert(ivd);
        ivd->draw(&painter,item);
    }
    painter.end();
}

void Renderer::display(std::shared_ptr<Item> item)
{
    std::shared_ptr<ShapeBase> shape = m_shapeLibrary.getShape(item->tag());
    shape->print(item);
}
