#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "concrete_commands/command.hpp"
#include "concrete_commands/AddCommand.hpp"
#include "concrete_commands/DivCommand.hpp"
#include "concrete_commands/MulCommand.hpp"
#include "concrete_commands/SubCommand.hpp"
#include "concrete_commands/QuitCommand.hpp"
#include "command_parser.hpp"

#include <memory>
#include <unordered_map>
#include <string>

class Controller{
    using CommandRegistry = std::unordered_map<std::string, std::unique_ptr<Command>>;
public:    
    Controller();
    void exec();

private:
    void run();
    void registerCommands();
    auto getInput();
    void handleInput(CommandParser::ParserResult&);
    Command* findCommand(const std::string&);
    double calculate(const std::string& command, const double op1 , const double op2);

private:
    CommandRegistry register_;
    CommandParser inputParser;
};

#endif //CONTROLLER_HPP