#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "io/consoleIO.hpp"
#include "cli/controller.hpp"

class Application{
public:
    static Application& instance()
    {
        static Application instance;
        return instance;
    }
    void exec();
    void quit();
    bool isRunning();

private:
    Application();

private:
    bool running;

private:
    ConsoleIO consoleLoger;
    Controller controller_;
};

#endif //APPLICATION_HPP
