#include "SaveCommand.hpp"
#include <fstream>

//#include "../../director/Director.hpp"
#include "../../Application.hpp"
#include "../../serializer/TxtSerializer.hpp"

SaveCommand::SaveCommand()
{
    m_arguments.initArgument("-file","new.txt");
}

std::string SaveCommand::exec()
{
    auto filename = m_arguments.getArgument<std::string>("-file");
    std::ofstream file(filename);
    TxtSerializer serializer(file);
    Application::instance().getDirector().saveDocument(serializer);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}