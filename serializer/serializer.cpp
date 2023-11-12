#include "serializer.hpp"
#include <fstream>
#include <iterator>
#include <sstream>

#include "../cli/command_factories/AddFactory.hpp"
#include "../cli/command_factories/CreateFactory.hpp"

#include "../director.hpp"


void Serializer::save(const std::string& filename)
{
    std::ofstream documnetFile("../save/"+filename);

    for(auto& slide : Director::getInstance().getDocument()){
        documnetFile<< *slide << "\n";
        for(const auto& [id,item] : *slide){
            documnetFile << "-name "<< item->info() << "\n";
        }
    }
}

void Serializer::load(const std::string& filename)
{
    std::ifstream documentFile("../save/" + filename);
    std::string line;
    
    while(getline(documentFile,line)){
        std::istringstream iss{line};
        std::vector<std::string> arguments(std::istream_iterator<std::string>{iss}, {});
        auto factory = selectFactory(*std::next(arguments.begin()));
        auto command = factory->makeCommand(arguments);
        command->exec();
    }
}

std::unique_ptr<CommandFactory> Serializer::selectFactory(const std::string &arg)
{
    if(arg == "Slide"){
        return std::make_unique<CreateFactory>();         
    }
    return std::make_unique<AddFactory>();
}
