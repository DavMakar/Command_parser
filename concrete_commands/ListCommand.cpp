#include "ListCommand.hpp"

std::string ListCommand::exec(Iterator argumentBegin, Iterator argumentEnd, ItemList &items)
{
    std::string result;
    for(const auto& [id , item] : items){
        result += id + " " + item->className() + "\n";
    }
    return result;
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}