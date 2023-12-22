#include "AddCommand.hpp"
#include "../../Application.hpp"
#include "../../director/actions/AddItemAction.hpp"

#include "../../document/BoundingBox.hpp"
#include "../../document/PenAttributes.hpp"
#include "../../document/TextAttributes.hpp"
#include "../../document/item.hpp"

#include <string>

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

    m_arguments.initArgument("-text", ""s);
    m_arguments.initArgument("-size",8);
    
}

void AddCommand::exec()
{
    Item::Item_tag itemTag = register_.findItem(m_arguments.getArgument<std::string>("-name"));
    
    BoundingBox box({m_arguments.getArgument<double>("-x1"),m_arguments.getArgument<double>("-y1")},
                    {m_arguments.getArgument<double>("-x2"),m_arguments.getArgument<double>("-y2")});

    PenAttributes penAttr(m_arguments.getArgument<std::string>("-color"),
                  m_arguments.getArgument<std::string>("-style"),
                  m_arguments.getArgument<int>("-w"));

    TextAttributes textAttr(m_arguments.getArgument<std::string>("-text"),
                            m_arguments.getArgument<int>("-size"));

    auto newItem = std::make_unique<Item>(itemTag, box, penAttr , textAttr);
    
    auto action = std::make_unique<AddItemAction>(Application::instance()->getDocument().getCurrentSlide() , std::move(newItem));
    Application::instance()->getDirector().runAction(std::move(action));
    Application::instance()->getUiController().logOutput("item added"); 
}


std::unique_ptr<Command> AddCommand::clone() const
{
    return std::make_unique<AddCommand>();
}


