#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "ioInterface.hpp"
#include "./document/document.hpp"
#include "commandCreator.hpp"

class Controller{
public:    
    Controller(IOInterface& io);
    void exec();

private:
    void run();
    std::vector<std::string> readInput();

private:
    bool isRunning = true;

private:
    Document doc; 
    IOInterface& IOStrategy_;
    CommandCreator creator;
};

#endif //CONTROLLER_HPP