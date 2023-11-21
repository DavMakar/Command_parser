#include "LoadCommand.hpp"
#include <fstream>

#include "../../director.hpp"
#include "../../serializer/DeserializerVisitor.hpp"

std::string LoadCommand::exec()
{
    std::string filename = *std::next(arguments_.begin());
    std::ifstream file(filename);
    DeserializerVisitor deserialVisitor(file);
    Director::getInstance().loadDocument(deserialVisitor);
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
