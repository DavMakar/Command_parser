#include "LoadCommand.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

std::string LoadCommand::exec(Document& slides)
{
    std::ifstream itemsFile{*std::next(arguments_.begin())};
    std::string itemLine;
    while(getline(itemsFile,itemLine)){
        std::istringstream iss{itemLine};
        std::vector<std::string> arguments(std::istream_iterator<std::string>{iss} , {});
        auto addCommand = factory.makeCommand(arguments);
        addCommand->exec(slides);
    }
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
