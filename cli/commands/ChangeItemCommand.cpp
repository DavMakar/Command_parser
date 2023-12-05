#include "ChangeItemCommand.hpp"
#include "../../Application.hpp"

ChangeItemCommand::ChangeItemCommand()
{
    m_arguments.initArgument("-id", 0);
}

std::string ChangeItemCommand::exec()
{
    auto id = std::stoi(*std::next(m_arguments.begin()));
    Application::instance().getDirector().changeItem(id,std::move(m_arguments));
    return "changed";
}

std::unique_ptr<Command> ChangeItemCommand::clone() const
{
    return std::make_unique<ChangeItemCommand>();
}
