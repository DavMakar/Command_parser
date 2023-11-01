#include "ChangeItemCommand.hpp"

std::string ChangeItemCommand::exec(IDocument &doc)
{
    auto id = *std::next(arguments_.begin());
    auto item = doc.getCurrentSlide()->getItemById(std::stoi(id));
    for(auto it =  std::next(arguments_.begin(),2); it != arguments_.end(); it+=2){
        item->setAttribute(*it,*std::next(it));
    } 
    return "changed";
}

std::unique_ptr<Command> ChangeItemCommand::clone() const
{
    return std::make_unique<ChangeItemCommand>();
}
