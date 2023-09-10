#include "controller.hpp"
#include <iostream>

Controller::Controller(){
    registerCommands();
}

void Controller::registerCommands(){
    register_["div"] = std::make_unique<DivCommand>();
    register_["add"] = std::make_unique<AddCommand>();
    register_["sub"] = std::make_unique<SubCommand>();
    register_["mul"] = std::make_unique<MulCommand>();
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
    std::string input;
    std::getline(std::cin , input);

    // std::copy(std::istreambuf_iterator<char>(std::cin) , std::istreambuf_iterator<char>() 
    // , back_inserter(input));

    std::stringstream ss(input);
    return inputParser.parse(ss);   
}

void Controller::handleInput(CommandParser::ParserResult& parseResult){
    auto [operation , operator1, operator2] = parseResult;
    std::cout<< calculate(operation, operator1, operator2) <<std::endl;
}

void Controller::run(){
    auto input = getInput();
    handleInput(input);
}

Command* Controller::findCommand(const std::string& command){
    auto command_iter = register_.find(command);
    if(command_iter == register_.end()){
        throw std::runtime_error("entered invalid command");
    }
    return command_iter->second.get();
}

double Controller::calculate(const std::string& command ,const double op1 ,const double op2){    
    return findCommand(command)->exec(op1,op2);
}