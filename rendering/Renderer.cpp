#include "Renderer.hpp"
#include "../document/Slide.hpp"
#include "../document/item.hpp"
#include "IVisualDisplayable.hpp"
#include "PenStyleConverter.hpp"
#include <QPainter>


void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice)
{
    QPainter painter;
    painter.begin(paintDevice);
    PenStyleConverter psConverter;
    //auto item = slide->getTopItem();

    for(auto [id,item] : *slide){
        painter.setPen(psConverter.toQPen(item->getPenStyle()));
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
