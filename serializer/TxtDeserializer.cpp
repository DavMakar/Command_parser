#include "TxtDeserializer.hpp"
#include <fstream>

#include "../document/document.hpp"
#include "../document/Point.hpp"

DeserializerVisitor::DeserializerVisitor(std::ifstream& file)
    : file_(file)
{
}

void DeserializerVisitor::visit(std::string& str)
{
    file_ >> str;
}

void DeserializerVisitor::visit(size_t& count)
{
    file_ >> count;
}

void DeserializerVisitor::visit(std::shared_ptr<Item>& i)
{
    i->accept(*this);
}

void DeserializerVisitor::visit(Point &p)
{
    p.accept(*this);
}

void DeserializerVisitor::visit(Slide& s)
{
    s.accept(*this);
}

void DeserializerVisitor::visit(Document& d)
{
    d.accept(*this);
}

void DeserializerVisitor::visit(Item::Item_tag& s)
{
    size_t tag;
    file_ >> tag;
    s = static_cast<Item::Item_tag>(tag);
}

void DeserializerVisitor::visit(double& d)
{
    file_ >> d;
}
