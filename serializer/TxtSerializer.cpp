#include "TxtSerializer.hpp"
#include <fstream>

#include "../document/Document.hpp"
#include "../document/Point.hpp"

TxtSerializer::TxtSerializer(std::ofstream &file)
    : file_(file)
{
}

void TxtSerializer::visit(std::string &str)
{
    file_ << str << " ";
}

void TxtSerializer::visit(size_t& count)
{
    file_ << count << " " ;
}

void TxtSerializer::visit(std::shared_ptr<Item> &i)
{
    file_ << std::endl;
    i->accept(*this);
}

void TxtSerializer::visit(Point &p)
{
    p.accept(*this);
}

void TxtSerializer::visit(Slide& s)
{
    file_ << std::endl;
    s.accept(*this);
}

void TxtSerializer::visit(Document &d)
{
    d.accept(*this);
}

void TxtSerializer::visit(Item::Item_tag &s)
{
    file_ << static_cast<size_t>(s)  << " ";    
}

void TxtSerializer::visit(double &d)
{
    file_ << d << " ";
}
