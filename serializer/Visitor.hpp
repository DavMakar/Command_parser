#ifndef VISITOR_HPP
#define VISITOR_HPP

class Slide;
class Document;
class Point;

#include <memory>
#include "../document/item.hpp"

class Visitor{
public:
    std::unique_ptr<Item> make_item(Item::Item_tag& tag);    
    virtual void visit(Item::Item_tag& s) = 0;
    virtual void visit(std::string& str) = 0;
    virtual void visit(Document& doc) = 0;
    virtual void visit(double& d) = 0;
    virtual void visit(size_t& count) = 0;
    virtual void visit(Slide& s) = 0;
    virtual void visit(std::shared_ptr<Item>& i) = 0;
};

#endif //VISITOR_HPP