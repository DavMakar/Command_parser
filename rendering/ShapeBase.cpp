#include "ShapeBase.hpp"
#include "../document/item.hpp"
#include "../Application.hpp"

void ShapeBase::print(std::shared_ptr<Item> item)
{
    Application::instance()->getUiController().logOutput(item->info());
}

std::unique_ptr<IShape> ShapeBase::clone()
{
    return std::make_unique<ShapeBase>();
}
