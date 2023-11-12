#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../ioInterface.hpp"
#include "commandCreator.hpp"

class Director;

class Controller{
public:    
    Controller(IOInterface& io);
    void run();
    
private:
    std::vector<std::string> readInput();

private:
    IOInterface& IOStrategy_;
    CommandCreator creator;
};

#endif //CONTROLLER_HPP