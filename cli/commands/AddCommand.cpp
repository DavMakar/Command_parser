#include "AddCommand.hpp"
#include "../../Application.hpp"
#include "../../director/AddItemAction.hpp"
#include <string>

using namespace std::literals;

AddCommand::AddCommand()
{
    m_arguments.initArgument("-name",""s);
    m_arguments.initArgument("-x",0);
    m_arguments.initArgument("-y",0.0);
    m_arguments.initArgument("-x1", 0.0);
    m_arguments.initArgument("-x2", 0.0);
    m_arguments.initArgument("-x3", 0.0);
    m_arguments.initArgument("-y1", 0.0);
    m_arguments.initArgument("-y2", 0.0);
    m_arguments.initArgument("-y3", 0.0);
    m_arguments.initArgument("-r", 0.0);
    m_arguments.initArgument("-text", ""s);
    m_arguments.initArgument("-size", 0);
}

std::string AddCommand::exec()
{
    auto newItem = register_.findItem(m_arguments.getArgument<std::string>("-name")); 

    for(auto& option : newItem->getOptions()){
        newItem->setAttribute(option , m_arguments[option]);
    }
    auto currentSlideIdx = Application::instance().getDirector().getCurrentSlideIndex();
    auto action = std::make_unique<AddItemAction>(Application::instance().getDocument().getSlide(currentSlideIdx) , newItem);

    Application::instance().getDirector().runAction(std::move(action));

    return "item added"; 
}


std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


