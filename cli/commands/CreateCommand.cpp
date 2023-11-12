#include "CreateCommand.hpp"
#include "../../director.hpp"

std::string CreateCommand::exec()
{
    Director::getInstance().addSlide();
    return "created slide";
}

std::unique_ptr<Command> CreateCommand::clone() const
{
    return std::make_unique<CreateCommand>();
}
