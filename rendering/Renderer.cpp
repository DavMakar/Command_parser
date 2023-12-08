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

    //TODO ShapeLibrary
    //auto item = slide->getTopItem();
    //std::shared_ptr<IShape> shape = ShapeLibrary::getShape(item);

    //for test
    auto item = std::make_shared<Rect>();
    std::shared_ptr<IShape> shape = std::make_shared<ShapeRect>();

    auto ivd = std::dynamic_pointer_cast<IVisualDisplayable>(shape);
    assert((ivd != nullptr));
    ivd->draw(&painter,item);
    painter.end();
}

void Renderer::display(std::shared_ptr<Item> item)
{
    //for test
    std::shared_ptr<ShapeBase> shape = std::make_shared<ShapeRect>();
    
    //std::shared_ptr<ShapeBase> shape = ShapeLibrary::getShape(item);
    shape->print(item);
}
