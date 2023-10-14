#include "SaveCommand.hpp"
#include <fstream>

std::string SaveCommand::exec(ItemList &items)
{
   
    //auto filePath = *std::next(argumentBegin);
    //std::string filename = filePath + "items.txt";

    std::string filename = *std::next(arguments_.begin());
    std::ofstream itemsFile(filename);

    for(const auto& [id,item] : items){
        itemsFile<<"-name "<< item->info() << "\n";
    }
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}