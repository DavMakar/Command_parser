#include "CreateCommand.hpp"
#include "../../director/Director.hpp"

using namespace std::literals;

CreateCommand::CreateCommand()
{
    arguments_.initArgument("-name", ""s);
}

std::string CreateCommand::exec()
{
    if(arguments_.getArgument<std::string>("-name") == "Slide"){
        Director::getInstance().addSlide();
    }else{
        throw std::runtime_error("-name Slide");
    }
    return "created slide";
}

std::unique_ptr<Command> CreateCommand::clone() const
{
    return std::make_unique<CreateCommand>();
}
