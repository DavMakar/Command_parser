#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <QPointF>
class iSerializer;

class Point {
public:
    Point() = default;
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    double x();
    double y();
    void accept(iSerializer& vi);

    operator auto(){
        return QPointF(m_x,m_y);
    }
    std::string info(); 
    std::string type();
private:
    double m_x = 0.0;
    double m_y = 0.0;
};

#endif //POINT_HPP
