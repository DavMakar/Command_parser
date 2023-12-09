#include "Renderer.hpp"
#include "../document/Slide.hpp"
#include "ShapeRect.hpp"
#include "../document/item.hpp"
#include "../document/Rect.hpp"
#include <QPainter>

void Renderer::draw(std::shared_ptr<Slide> slide, QPaintDevice* paintDevice)
{
    QPainter painter;
    painter.begin(paintDevice);

    //auto item = slide->getTopItem();

    //for test
    auto item = std::make_shared<Rect>();
    std::shared_ptr<IShape> shape = m_shapeLibrary.getShape(item->tag());

    auto ivd = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
    assert((ivd != nullptr));
    ivd->draw(&painter,item);
    painter.end();
}

void Renderer::display(std::shared_ptr<Item> item)
{
    std::shared_ptr<ShapeBase> shape = m_shapeLibrary.getShape(item->tag());
    shape->print(item);
}
