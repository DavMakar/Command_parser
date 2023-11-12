#include "controller.hpp"

Controller::Controller(IOInterface& io): 
    IOStrategy_{io}
{
}

std::vector<std::string> Controller::readInput()
{
    return IOStrategy_.getInput("Enter command : ");
}

void Controller::run(){
    auto input = readInput();
    std::string commandName = input.front();
    auto command = creator.createCommand(commandName, {std::next(input.begin()),input.end()});
    auto result = command->exec();
    IOStrategy_.printOutput(result);
}

