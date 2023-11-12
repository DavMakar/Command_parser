#include "LoadCommand.hpp"
#include "../../director.hpp"

std::string LoadCommand::exec()
{
    std::string filename = *std::next(arguments_.begin());
    Director::getInstance().loadDocument(loader,filename);
 
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
