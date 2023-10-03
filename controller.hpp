#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "command_parser.hpp"
#include "ioInterface.hpp"
#include "item.hpp"

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

class Controller{
    using ItemList = std::unordered_map<std::string , std::unique_ptr<Item>>;
public:    
    Controller(IOInterface& io);
    void exec();

private:
    void run();
    auto readInput();

private:
    ItemList items;
    IOInterface& IOStrategy_;
    CommandParser inputParser;
};

#endif //CONTROLLER_HPP