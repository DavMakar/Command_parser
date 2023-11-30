#include "Application.hpp"

void Application::exec()
{
    while (isRunning())
    {
        try{
            controller_.run();
        }
        catch(const std::exception& e){
            consoleLoger.printOutput(e.what());
        }
    }
}

void Application::quit()
{
    running = false;
}

bool Application::isRunning()
{
    return running;
}

Application::Application()
    :running(true) , controller_(consoleLoger)
{
}
