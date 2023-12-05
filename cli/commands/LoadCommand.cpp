#include "LoadCommand.hpp"
#include <fstream>

#include "../../Application.hpp"
#include "../../serializer/TxtDeserializer.hpp"

LoadCommand::LoadCommand()
{
    m_arguments.initArgument("-file", "new.txt");
}

std::string LoadCommand::exec()
{
    auto filename = m_arguments.getArgument<std::string>("-file");
    std::ifstream file(filename);
    TxtDeserializer deserializer(file);
    
    Application::instance().getDirector().loadDocument(deserializer);
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
