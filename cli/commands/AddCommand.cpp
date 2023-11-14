#include "AddCommand.hpp"
#include "../../director.hpp"
#include "../../document/ItemVisitor.hpp"

std::string AddCommand::exec()
{
    ItemVisitor vi(arguments_);
    std::string item_type;
    vi.visit(item_type);
    auto newItem = vi.makeShape(item_type);
    newItem->accept(vi);   
//    auto newItem = register_.findItem(*std::next(arguments_.begin()));
//    newItem->init(std::next(arguments_.begin(),2),arguments_.end());
    Director::getInstance().addItemToSlide(std::move(newItem));

    return "item added"; 
}


std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


