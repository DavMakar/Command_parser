#ifndef DESERIALIZER_VISITOR_HPP
#define DESERIALIZER_VISITOR_HPP

#include "Visitor.hpp"

class DeserializerVisitor: public Visitor{
public:
    DeserializerVisitor(std::ifstream& file);
    void readNextLine(std::string& line);
    virtual void visit(std::string& str) override;
    virtual void visit(size_t& count) override;
    virtual void visit(std::shared_ptr<Item>& i) override ;
    virtual void visit(Point& p) override;
    virtual void visit(Slide& s) override ;
    virtual void visit(Document& d) override ;
    virtual void visit(Item::Item_tag& s) override ;
    virtual void visit(double& d) override ;
private:
    std::ifstream& file_;
};

#endif //DESERIALIZER_VISITOR_HPP
