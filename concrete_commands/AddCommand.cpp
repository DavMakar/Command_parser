#include "AddCommand.hpp"

std::string AddCommand::exec(IDocument& doc)
{
    auto newItem = register_.findItem(*std::next(arguments_.begin()));
    newItem->init(std::next(arguments_.begin(),2),arguments_.end());

    documentDirector_.addItemToSlide(doc,std::move(newItem));

    std::string result = "item added to slide " + doc.getCurrentSlideIndex();
    return result; 
}

std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


