#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "concrete_commands/command.hpp"
#include "command_parser.hpp"
#include "ioInterface.hpp"
#include "commandRegistry.hpp"

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

class Controller{
    //using CommandRegistry = std::unordered_map<std::string, std::unique_ptr<Command>>;
public:    
    Controller(IOInterface& io);
    void exec();

private:
    void run();
    void registerCommands();
    auto readInput();
    void handleInput(const std::string& operator_ ,const std::vector<double>& operands_);
    Command* findCommand(const std::string&);
    double calculate(const std::string& command, const std::vector<double>& operands_);

private:
    IOInterface& IOStrategy_;
    CommandParser inputParser;
};

#endif //CONTROLLER_HPP