#include "TxtSerializer.hpp"
#include <fstream>

#include "../document/document.hpp"
#include "../document/Point.hpp"

SerializerVisitor::SerializerVisitor(std::ofstream &file)
    : file_(file)
{
}

void SerializerVisitor::visit(std::string &str)
{
    file_ << str << " ";
}

void SerializerVisitor::visit(size_t& count)
{
    file_ << count << " " ;
}

void SerializerVisitor::visit(std::shared_ptr<Item> &i)
{
    file_ << std::endl;
    i->accept(*this);
}

void SerializerVisitor::visit(Point &p)
{
    p.accept(*this);
}

void SerializerVisitor::visit(Slide& s)
{
    file_ << std::endl;
    s.accept(*this);
}

void SerializerVisitor::visit(Document &d)
{
    d.accept(*this);
}

void SerializerVisitor::visit(Item::Item_tag &s)
{
    file_ << static_cast<size_t>(s)  << " ";    
}

void SerializerVisitor::visit(double &d)
{
    file_ << d << " ";
}
