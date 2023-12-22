#include "ListCommand.hpp"
#include "../../Application.hpp"

void ListCommand::exec()
{
    std::string result;
    int slideIdx{1};
    for(auto slide : Application::instance()->getDocument()){
        result += "Slide id: " + std::to_string(slideIdx) + "\n";
        for(const auto& item : *slide){
            result += "   " + item->type() + " id: " +  std::to_string(item->getId())+ "\n";
        }
        ++slideIdx;
    }
    Application::instance()->getUiController().logOutput(result);
}

std::unique_ptr<Command> ListCommand::clone() const
{
    return std::make_unique<ListCommand>();
}
