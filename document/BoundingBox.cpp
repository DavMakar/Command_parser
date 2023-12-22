#include "BoundingBox.hpp"
#include "../serializer/iSerializer.hpp"

BoundingBox::BoundingBox(Point topLeft, Point bottomRight)
    : m_topLeft(topLeft) , m_bottomRight(bottomRight)
{
}

Point BoundingBox::getTopLeft() const
{
    return m_topLeft;
}

Point BoundingBox::getBottomRight() const
{
    return m_bottomRight;
}

void BoundingBox::accept(iSerializer& se)
{
    se.visit(m_topLeft);
    se.visit(m_bottomRight);
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


