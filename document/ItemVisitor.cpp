#include "ItemVisitor.hpp"
#include "Rect.hpp"
#include "Point.hpp"
//#include "Circle.hpp"

ItemVisitor::ItemVisitor(std::vector<std::string> itemTokens)
    :itemType(itemTokens[0])
{
    for(auto& token : itemTokens){
        std::stringstream parser(token);
        double d;
        parser >> d;
        if(parser.fail()){
            parser.clear();
            continue;
        }
        values.push(d);
    }
}

void ItemVisitor::visit(Rect &rect)
{
    rect.accept(*this);
}

// void ItemVisitor::visit(Circle& circle){
//     circle.accept(*this);
// }

void ItemVisitor::visit(Point& point){
    point.accept(*this);
}
void ItemVisitor::visit(double& d){
    d = values.front();
    values.pop();
}

void ItemVisitor::visit(std::string &type)
{
    type = itemType;
}
