#include "serializer.hpp"
#include <fstream>
#include <iterator>
#include <sstream>
#include "../command_factories/AddFactory.hpp"
#include "../command_factories/CreateFactory.hpp"


void Serializer::save(Document& doc, const std::string& filename)
{
    std::ofstream documnetFile("../save/"+filename);

    for(auto& slide : doc.getSlides()){
        documnetFile<< *slide << "\n";
        for(const auto& [id,item] : *slide){
            documnetFile << "-name "<< item->info() << "\n";
        }
    }
}

void Serializer::load(Document& doc, const std::string& filename)
{
    std::ifstream documentFile("../save/" + filename);
    std::string line;
    
    while(getline(documentFile,line)){
        std::istringstream iss{line};
        std::vector<std::string> arguments(std::istream_iterator<std::string>{iss}, {});
        auto factory = selectFactory(*std::next(arguments.begin()));
        auto command = factory->makeCommand(arguments);
        command->exec(doc);
    }
}

std::unique_ptr<CommandFactory> Serializer::selectFactory(const std::string &arg)
{
    if(arg == "Slide"){
        return std::make_unique<CreateFactory>();         
    }
    return std::make_unique<AddFactory>();
}
