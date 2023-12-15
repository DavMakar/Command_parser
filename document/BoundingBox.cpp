#include "BoundingBox.hpp"

BoundingBox::BoundingBox(Point topLeft, Point bottomRight)
    : m_topLeft(topLeft) , m_bottomRight(bottomRight)
{
}

Point BoundingBox::getTopLeft()
{
    return m_topLeft;
}

Point BoundingBox::getBottomRight(){
    return m_bottomRight;
}

void BoundingBox::setTopLeftX(double x)
{
    m_topLeft.setX(x);
}

void BoundingBox::setTopLetfY(double y)
{
    m_topLeft.setY(y);
}

void BoundingBox::setBottomRightX(double x)
{
    m_bottomRight.setX(x);
}

void BoundingBox::setBottomRightY(double y)
{
    m_bottomRight.setY(y);
}

