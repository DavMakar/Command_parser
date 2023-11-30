#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../io/ioInterface.hpp"
#include "commandCreator.hpp"
#include <sstream>

class Controller{
public:    
    Controller(IOInterface& io);
    void run();
    
private:
    std::istringstream readInput();

private:
    IOInterface& IOStrategy_;
    CommandCreator creator;
};

#endif //CONTROLLER_HPP