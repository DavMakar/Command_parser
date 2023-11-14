#ifndef VISITOR_HPP
#define VISITOR_HPP

class Point;
class Rect;
class Circle;

#include "item.hpp"

class Visitor{
public:
    std::unique_ptr<Item> makeShape(std::string& type); 
    virtual void visit(std::string& type) = 0;
    virtual void visit(double& d) = 0;
    virtual void visit(Point& p) = 0;
    virtual void visit(Rect& rect) = 0; 
    //virtual void visit(Circle& circle) = 0;
};

#endif //VISITOR_HPP