#include "ListCommand.hpp"

std::string ListCommand::exec(Document& doc)
{
    return doc.displayAllSlides();
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}