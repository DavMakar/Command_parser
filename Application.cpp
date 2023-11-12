#include "Application.hpp"

Application::Application(IOInterface &io): 
    isRunning{true}, consoleLoger{io}, controller_{io}
{
}

void Application::exec()
{
    while (isRunning)
    {
        try{
            controller_.run();
        }
        catch(const std::exception& e){
            consoleLoger.printOutput(e.what());
        }
    }
}
