#include "SaveCommand.hpp"
#include <fstream>

#include "../../director.hpp"
#include "../../serializer/SerializerVisitor.hpp"

std::string SaveCommand::exec()
{
    std::string filename = *std::next(arguments_.begin());
    std::ofstream file(filename);

    SerializerVisitor serialVisitor(file);
    Director::getInstance().saveDocument(serialVisitor);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}