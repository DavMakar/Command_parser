#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "command.hpp"
#include "concrete_commnads.hpp"
#include "command_parser.hpp"
#include <memory>
#include <unordered_map>
#include <string>

class Controller{
    using CommandRegistry = std::unordered_map<std::string, std::unique_ptr<Command>>;
public:    
    Controller();
    void run();

private:
    void registerCommands();
    auto getInput();
    void handleInput(CommandParser::ParserResult&);
    std::unique_ptr<Command> findCommand(const std::string&);
    double calculate(const std::string& command, const double op1 , const double op2);

private:
    CommandRegistry register_;
    CommandParser inputParser;
};

#endif //CONTROLLER_HPP