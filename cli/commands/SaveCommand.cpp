#include "SaveCommand.hpp"
#include <fstream>

#include "../../director/Director.hpp"
#include "../../serializer/TxtSerializer.hpp"

SaveCommand::SaveCommand()
{
    arguments_.initArgument("-file","new.txt");
}

std::string SaveCommand::exec()
{
    auto filename = arguments_.getArgument<std::string>("-file");
    std::ofstream file(filename);
    SerializerVisitor serialVisitor(file);
    Director::getInstance().saveDocument(serialVisitor);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}