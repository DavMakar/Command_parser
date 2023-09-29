#include "AddCommand.hpp"
#include <numeric>

std::string AddCommand::exec(Iterator argumentBegin , Iterator argumentEnd, ItemList& items)
{
    if(args.find(*argumentBegin) == args.end()){
        throw std::runtime_error("to add item write -name [Item name]");
    }
 
    auto newItem = std::move(register_.findItem(*std::next(argumentBegin)));
    newItem->init(std::next(argumentBegin,2),argumentEnd);
    auto newItemId = std::to_string(newItem->getId());
    items[newItemId] = std::move(newItem);

    std::string result = "item added with id " + newItemId;
    return result; 
}

std::unique_ptr<Command> AddCommand::clone() const
{
    //return std::make_unique<AddCommand>(*this);
    return std::make_unique<AddCommand>();
}

