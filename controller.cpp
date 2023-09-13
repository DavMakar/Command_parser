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
    // std::copy(std::istreambuf_iterator<char>(std::cin) , std::istreambuf_iterator<char>() 
    // , back_inserter(input));
    return IOStrategy_.getInput();
}

void Controller::handleInput(const std::string& operator_, const std::vector<double>& operands_){
    IOStrategy_.printOutput(std::to_string(calculate(operator_, operands_)));
}

void Controller::run(){
    auto input = readInput();
    inputParser.parse(input[0]);
    handleInput(inputParser.get_operator(),inputParser.get_operands());
}

double Controller::calculate(const std::string& command , const std::vector<double>& operands_){    
    return findCommand(command)->exec(operands_);
}