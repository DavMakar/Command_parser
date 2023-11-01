#include "CreateCommand.hpp"

std::string CreateCommand::exec(IDocument &doc)
{
    documentDirector_.addSlide(doc);
    return "created slide";
}

std::unique_ptr<Command> CreateCommand::clone() const
{
    return std::make_unique<CreateCommand>();
}
