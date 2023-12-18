#include "AddCommand.hpp"
#include "../../Application.hpp"
#include "../../director/actions/AddItemAction.hpp"
#include <string>
#include "../../document/BoundingBox.hpp"

using namespace std::literals;

AddCommand::AddCommand()
{
    m_arguments.initArgument("-name",""s);
// bounding box
    m_arguments.initArgument("-x1", 0.0);
    m_arguments.initArgument("-x2", 0.0);
    m_arguments.initArgument("-y1", 0.0);
    m_arguments.initArgument("-y2", 0.0);

    m_arguments.initArgument("-x3", 0.0);
    m_arguments.initArgument("-y3", 0.0);

    m_arguments.initArgument("-color", "#000000");
    m_arguments.initArgument("-style", "SolidLine");
    m_arguments.initArgument("-w", 1);

    m_arguments.initArgument("-content", ""s);
    
    //m_arguments.initArgument("-size", 0);
}

void AddCommand::exec()
{
    //item creation and init
    auto newItem = register_.findItem(m_arguments.getArgument<std::string>("-name")); 
    BoundingBox box({m_arguments.getArgument<double>("-x1"),m_arguments.getArgument<double>("-y1")},
                    {m_arguments.getArgument<double>("-x2"),m_arguments.getArgument<double>("-y2")});
    newItem->setBoundingBox(box);

    for(auto& option : newItem->getOptions()){
        newItem->setAttribute(option , m_arguments[option]);
    }

    std::string penColor = m_arguments.getArgument<std::string>("-color");
    std::string penStyle = m_arguments.getArgument<std::string>("-style");
    int penWidth = m_arguments.getArgument<int>("-w");
    PenStyle ps(penColor,penStyle,penWidth);
    newItem->setPenStyle(ps);

    auto action = std::make_unique<AddItemAction>(Application::instance()->getDocument().getCurrentSlide() , std::move(newItem));
    Application::instance()->getDirector().runAction(std::move(action));
    Application::instance()->getUiController().logOutput("item added"); 
}


std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


