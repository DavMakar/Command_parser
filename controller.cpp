#include "controller.hpp"

#include "concrete_commands/AddCommand.hpp"
#include "concrete_commands/DivCommand.hpp"
#include "concrete_commands/MulCommand.hpp"
#include "concrete_commands/SubCommand.hpp"
#include "concrete_commands/QuitCommand.hpp"
#include "concrete_commands/AndCommand.hpp"
#include "concrete_commands/OrCommand.hpp"
#include "concrete_commands/NotCommand.hpp"

#include <iostream>

Controller::Controller(IOInterface& io): IOStrategy_{io}
{
    registerCommands();
}

void Controller::registerCommands(){
    register_["div"] = std::make_unique<DivCommand>();
    register_["add"] = std::make_unique<AddCommand>();
    register_["sub"] = std::make_unique<SubCommand>();
    register_["mul"] = std::make_unique<MulCommand>();
    register_["and"] = std::make_unique<AndCommand>();
    register_["not"] = std::make_unique<NotCommand>();
    register_["or"] = std::make_unique<OrCommand>();
    register_["quit"] = std::make_unique<QuitCommand>();
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
            std::cerr << e.what() << '\n';
        }
    }
}

auto Controller::getInput(){
    // std::copy(std::istreambuf_iterator<char>(std::cin) , std::istreambuf_iterator<char>() 
    // , back_inserter(input));
    std::stringstream ss(IOStrategy_.getInput("Enter command and arguments: "));
    return ss;
}

void Controller::handleInput(const std::string& operator_, const std::vector<double>& operands_){
    IOStrategy_.printOutput(std::to_string(calculate(operator_, operands_)));
}

void Controller::run(){
    auto input = getInput();
    inputParser.tokenize(input);
    handleInput(inputParser.get_operator(),inputParser.get_operands());
}

Command* Controller::findCommand(const std::string& command){
    auto command_iter = register_.find(command);
    if(command_iter == register_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return command_iter->second.get();
}

double Controller::calculate(const std::string& command , const std::vector<double>& operands_){    
    return findCommand(command)->exec(operands_);
}