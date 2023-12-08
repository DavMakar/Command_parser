#include "commandCreator.hpp"

#include <sstream>

std::unique_ptr<Command> CommandCreator::CreateSlideCommand(std::istream& stream)
{
    std::string commandName;
    stream >> commandName;
    auto command = commandRegistry_.findCommand(commandName);
    parseArguments(stream, *command);
    return command;   
}

void CommandCreator::parseArguments(std::istream &stream, Command& command)
{
    std::string key;
    while(stream >> key){
        if(key == "-name"){
            std::string itemType;
            stream >> itemType;
            command.m_arguments.setArgument(key,itemType);
        }
        else if(key == "-x1" || key == "-x2" || key == "-y1" || key == "-y2" || 
           key == "-x"  || key == "-y" || key == "-r"){ 
            double value;
            stream >> value;
            command.m_arguments.setArgument(key,value);
        }
        else if(key == "-size" || key == "-id"){ 
            int value;
            stream >> value;       
            command.m_arguments.setArgument(key,value);
        }
        else{
            throw std::runtime_error("invalid key " + key);
        }
    }
}
