#include "ListCommand.hpp"

std::string ListCommand::exec(ItemList &items)
{
    std::string result;
    for(const auto& [id , item] : items){
        result += id + " " + item->type() + "\n";
    }
    return result;
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}