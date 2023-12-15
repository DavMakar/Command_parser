#include "TxtDeserializer.hpp"
#include <fstream>

#include "../document/Document.hpp"
#include "../document/Point.hpp"

TxtDeserializer::TxtDeserializer(std::ifstream& file)
    : file_(file)
{
}

void TxtDeserializer::visit(std::string& str)
{
    file_ >> str;
}

void TxtDeserializer::visit(size_t& count)
{
    file_ >> count;
}

void TxtDeserializer::visit(std::shared_ptr<Item>& i)
{
    i->accept(*this);
}

void TxtDeserializer::visit(BoundingBox &box)
{
}

void TxtDeserializer::visit(Point &p)
{
    p.accept(*this);
}

void TxtDeserializer::visit(Slide& s)
{
    s.accept(*this);
}

void TxtDeserializer::visit(Document& d)
{
    d.accept(*this);
}

void TxtDeserializer::visit(Item::Item_tag& s)
{
    size_t tag;
    file_ >> tag;
    s = static_cast<Item::Item_tag>(tag);
}

void TxtDeserializer::visit(double& d)
{
    file_ >> d;
}
