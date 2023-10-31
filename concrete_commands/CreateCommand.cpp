#include "CreateCommand.hpp"

std::string CreateCommand::exec(Document &doc)
{
    doc.addSlide();
    return "created slide";
}

std::unique_ptr<Command> CreateCommand::clone() const
{
    return std::make_unique<CreateCommand>();
}
