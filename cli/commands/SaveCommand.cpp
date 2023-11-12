#include "SaveCommand.hpp"
#include <fstream>

#include "../../director.hpp"

std::string SaveCommand::exec()
{
    std::string filename = *std::next(arguments_.begin());
    Director::getInstance().saveDocument(saver, filename);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}