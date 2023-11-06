#include "DisplayCommand.hpp"

std::string DisplayCommand::exec(Document& doc)
{
    auto id = *std::next(arguments_.begin());
    return doc.displaySlideItem(std::stoi(id));
}

std::unique_ptr<Command> DisplayCommand::clone() const
{
    return std::make_unique<DisplayCommand>();
}
