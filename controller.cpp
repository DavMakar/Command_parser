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
    std::string commandName = input[0];
    // auto command = commandFactory::createCommand
    auto command = creator.createCommand(commandName, {std::next(input.begin()),input.end()});
    auto result = command->exec(items);
    // FIX 
    IOStrategy_.printOutput(result);
}