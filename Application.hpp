#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "cli/controller.hpp"

class IOInterface;

class Application{
public:
    Application(IOInterface& io);
    void exec();

public:
    bool isRunning;

private:
    IOInterface& consoleLoger;
    Controller controller_;
};

#endif //APPLICATION_HPP
