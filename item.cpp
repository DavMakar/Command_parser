#include "item.hpp"

int Item::counter = 0;

Item::Item()
{
    id_ = ++counter;
}

int Item::getId()
{
    return id_;
}

Item::~Item()
{
}
