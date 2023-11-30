#ifndef POINT_HPP
#define POINT_HPP

#include <string>

class Visitor;

class Point {
public:
    Point() = default;
    Point(double x, double y);
    void setX(double x);
    void setY(double y);
    void accept(Visitor& vi);

    std::string info(); 
    std::string type();
private:
    double x_;
    double y_;
};

#endif //POINT_HPP