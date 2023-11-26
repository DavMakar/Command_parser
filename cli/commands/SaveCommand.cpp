#include "SaveCommand.hpp"
#include <fstream>

#include "../../director.hpp"
#include "../../serializer/TxtSerializer.hpp"

std::string SaveCommand::exec()
{
    std::string filename = *std::next(arguments_.begin());
    std::ofstream file(filename);

    TxtSerializer serializer(file);
    Director::getInstance().saveDocument(serializer);
    return "saved";
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}
