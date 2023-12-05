#include "CreateCommand.hpp"
#include "../../Application.hpp"

using namespace std::literals;

CreateCommand::CreateCommand()
{
    m_arguments.initArgument("-name", ""s);
}

std::string CreateCommand::exec()
{
    if(m_arguments.getArgument<std::string>("-name") == "Slide"){
        Application::instance().getDirector().addSlide();
    }else{
        throw std::runtime_error("-name Slide");
    }
    return "created slide";
}

std::unique_ptr<Command> CreateCommand::clone() const
{
    return std::make_unique<CreateCommand>();
}
