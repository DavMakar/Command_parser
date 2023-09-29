#include "controller.hpp"


Controller::Controller(IOInterface& io): 
    IOStrategy_{io}
{
}

void Controller::exec(){
    while (true)
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

auto Controller::readInput(){
    return IOStrategy_.getInput("Enter command : ");
}

void Controller::run(){
    auto input = readInput();
    auto command = inputParser.parse(input[0]);

    auto result = command->exec(std::next(input.begin()) , input.end(), items);
    // FIX 
    IOStrategy_.printOutput(result);
}