#include "ShapeLibrary.hpp"
#include "ShapeRect.hpp"
#include "ShapeText.hpp"
#include "ShapeEllipse.hpp"

ShapeLibrary::ShapeLibrary()
{
    m_lib[Item::Item_tag::RECT] = std::make_unique<ShapeRect>();
    m_lib[Item::Item_tag::ELLIPSE] = std::make_unique<ShapeEllipse>();   
    m_lib[Item::Item_tag::TEXT] = std::make_unique<ShapeText>();
}

std::shared_ptr<ShapeBase> ShapeLibrary::getShape(Item::Item_tag tag)
{
    return m_lib[tag];
}
