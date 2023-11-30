#include "controller.hpp"

Controller::Controller(IOInterface& io): 
    IOStrategy_{io}
{
}

std::istringstream Controller::readInput()
{
    return IOStrategy_.getInput("Enter command : ");
}


void Controller::run(){
    auto input = readInput();
    auto command = creator.createCommand(input);
    auto result = command->exec();
    IOStrategy_.printOutput(result);
}

