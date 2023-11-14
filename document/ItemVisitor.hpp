#include "Visitor.hpp"
#include <sstream>
#include <queue>


class ItemVisitor: public Visitor{
public:
    ItemVisitor(std::vector<std::string> itemTokens);
    void visit(Rect& rect);
    void visit(Point& point);
    //void visit(Circle& circle);
    void visit(double& d);
    void visit(std::string& type);
private:
    std::string itemType;
    std::queue<double> values;
};