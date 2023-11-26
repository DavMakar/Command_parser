#include "LoadCommand.hpp"
#include <fstream>

#include "../../director.hpp"
#include "../../serializer/TxtDeserializer.hpp"

std::string LoadCommand::exec()
{
    std::string filename = *std::next(arguments_.begin());
    std::ifstream file(filename);
    TxtDeserializer deserializer(file);
    Director::getInstance().loadDocument(deserializer);
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
