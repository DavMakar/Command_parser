#ifndef TXT_SERIALIZER_HPP
#define TXT_SERIALIZER_HPP

#include "Visitor.hpp"

class TxtSerializer: public Visitor{
public:
    TxtSerializer(std::ofstream& file);
    virtual void visit(std::string& str) override;
    virtual void visit(size_t& count) override;
    virtual void visit(std::shared_ptr<Item>& i) override ;
    virtual void visit(Slide& s) override ;
    virtual void visit(Point& p) override;
    virtual void visit(Document& d) override ;
    virtual void visit(Item::Item_tag& s) override ;
    virtual void visit(double& d) override ;
private:
    std::ofstream& file_;
};

#endif //TXT_SERIALIZER_HPP
