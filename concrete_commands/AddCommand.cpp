#include "AddCommand.hpp"
#include "../Rect.hpp"
#include <numeric>

AddCommand::AddCommand()
{
    registerItems();
}

std::string AddCommand::exec(Iterator argumentBegin, Iterator argumentEnd, ItemList &items)
{
    if(args.find(*argumentBegin) == args.end()){
        throw std::runtime_error("to add item write -name [Item name]");
    }
 
    auto newItem = register_.findEntry(*std::next(argumentBegin));
    newItem->init(std::next(argumentBegin,2),argumentEnd);
    auto newItemId = std::to_string(newItem->getId());
    items[newItemId] = std::move(newItem);

    std::string result = "item added with id " + newItemId;
    return result; 
}

std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}

void AddCommand::registerItems()
{
    register_.registerEntry("Rect", std::make_unique<Rect>());
}
