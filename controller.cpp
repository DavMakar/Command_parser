#include "controller.hpp"

Controller::Controller(IOInterface& io): 
    IOStrategy_{io}
{
}

void Controller::exec(){
    while (isRunning)
    {
        try
        {
            run();
        }
        catch(const std::exception& e)
        {
            IOStrategy_.printOutput(e.what());
        }
    }
}

std::vector<std::string> Controller::readInput()
{
    return IOStrategy_.getInput("Enter command : ");
}

void Controller::run(){
    auto input = readInput();
    std::string commandName = input.front();
    auto command = creator.createCommand(commandName, {std::next(input.begin()),input.end()});
    auto result = command->exec(doc);
    // FIX 
    IOStrategy_.printOutput(result);
}



