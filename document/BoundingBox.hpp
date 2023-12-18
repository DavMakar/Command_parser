#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include "Point.hpp"
#include <QRectF>

class ISerializer;

class BoundingBox{
public:
    BoundingBox() = default;
    BoundingBox(Point topLeft , Point bottomRight);
    Point getTopLeft();
    Point getBottomRight();

    void accept(iSerializer& se);

    void setTopLeftX(double x);
    void setTopLetfY(double y);
    void setBottomRightX(double x);
    void setBottomRightY(double y);

    operator auto(){
        return QRectF(m_topLeft, m_bottomRight);
    }

private:
    Point m_topLeft;
    Point m_bottomRight;
};

#endif //BOUNDING_BOX_HPP
