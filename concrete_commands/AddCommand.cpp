#include "AddCommand.hpp"
#include "../Rect.hpp"
#include <numeric>

AddCommand::AddCommand()
{
    registerItems();
}

std::string AddCommand::exec(ItemList &items)
{
    auto newItem = register_.findEntry(*std::next(arguments_.begin()));
    newItem->init(std::next(arguments_.begin(),2),arguments_.end());
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
