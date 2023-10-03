#include "LoadCommand.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

std::string LoadCommand::exec(Iterator argumentBegin, Iterator argumentEnd, ItemList &items)
{
    if(args.find(*argumentBegin) == args.end()){
        throw std::runtime_error("write -file [path]");
    }
    std::ifstream itemsFile{*std::next(argumentBegin)};
    std::string itemLine;
    while(getline(itemsFile,itemLine)){
        std::istringstream iss{itemLine};
        std::vector<std::string> arguments(std::istream_iterator<std::string>{iss} , {});
        add_.exec(arguments.begin(),arguments.end(),items);
    }
    return "loaded";
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
