#include "SaveCommand.hpp"
#include <fstream>

std::string SaveCommand::exec(Document& doc)
{
   
    //auto filePath = *std::next(argumentBegin);
    //std::string filename = filePath + "items.txt";

    std::string filename = *std::next(arguments_.begin());
    doc.save(filename);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}