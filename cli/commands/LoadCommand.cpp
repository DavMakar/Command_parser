#include "LoadCommand.hpp"
#include <fstream>

#include "../../director/Director.hpp"
#include "../../serializer/TxtDeserializer.hpp"

LoadCommand::LoadCommand()
{
    arguments_.initArgument("-file", "new.txt");
}

std::string LoadCommand::exec()
{
    auto filename = arguments_.getArgument<std::string>("-file");
    std::ifstream file(filename);
    DeserializerVisitor deserialVisitor(file);
    Director::getInstance().loadDocument(deserialVisitor);
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
