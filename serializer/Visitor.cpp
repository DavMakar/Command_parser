#include "Visitor.hpp"
#include "../document/Rect.hpp"

std::unique_ptr<Item> Visitor::make_item(Item::Item_tag &tag)
{
    switch (tag)
    {
    case Item::Item_tag::Rect:
        return std::make_unique<Rect>(); 
    }
}
