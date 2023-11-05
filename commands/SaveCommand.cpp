#include "SaveCommand.hpp"
#include <fstream>

std::string SaveCommand::exec(IDocument& doc)
{
    std::string filename = *std::next(arguments_.begin());
    documentDirector_.saveDocument(doc,filename);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}