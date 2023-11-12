#include "AddCommand.hpp"
#include "../../director.hpp"

std::string AddCommand::exec()
{
    auto newItem = register_.findItem(*std::next(arguments_.begin()));
    newItem->init(std::next(arguments_.begin(),2),arguments_.end());

    Director::getInstance().addItemToSlide(std::move(newItem));

    return "item added"; 
}


std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


