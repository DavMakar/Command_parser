#include "calculator.hpp"
#include <iostream>

Calculator::Calculator(){
    initCommandRegistry();
}

void Calculator::initCommandRegistry(){
    register_["div"] = std::make_unique<DivCommand>();
    register_["add"] = std::make_unique<AddCommand>();
    register_["sub"] = std::make_unique<SubCommand>();
    register_["mul"] = std::make_unique<MulCommand>();
}

double Calculator::calculate(const std::string& command ,const double op1 ,const double op2){
    CommandRegistry::const_iterator command_iter = register_.find(command);
    if(command_iter != register_.end()){
        return register_[command].get()->exec(op1,op2);
    }else{
        std::cout << "entered false command" << std::endl;
    }
    // try{
    //     register_[command].get()->exec(op1,op2);
    // }
    // catch(std::out_of_range& e){
    //     std::cout << "entered false command" << std::endl;
    // }
}