#ifndef POINT_HPP
#define POINT_HPP

#include <string>

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

    std::string info(); 
    std::string type();
private:
    double m_x;
    double m_y;
};

#endif //POINT_HPP