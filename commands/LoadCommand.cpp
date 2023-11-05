#include "LoadCommand.hpp"

std::string LoadCommand::exec(Document& doc)
{
    std::string filename = *std::next(arguments_.begin());
    documentDirector_.loadDocument(doc,filename);
 
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
