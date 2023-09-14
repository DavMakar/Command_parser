#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

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
    auto readInput();

private:
    IOInterface& IOStrategy_;
    CommandParser inputParser;
};

#endif //CONTROLLER_HPP