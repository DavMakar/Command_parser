#include "ListCommand.hpp"
#include "../../Application.hpp"

void ListCommand::exec()
{
    std::string result;
    int slideIdx{1};
    for(auto slide : Application::instance()->getDocument()){
        result += "Slide id: " + std::to_string(slideIdx) + "\n";
        for(const auto& [id,item]: *slide){
            result += "   " + item->type() + " id: " +  std::to_string(id)+ "\n";
        }
        ++slideIdx;
    }
    Application::instance()->getController().logOutput(result);
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}
