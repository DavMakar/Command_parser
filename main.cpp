#include "controller.hpp"
#include "consoleIO.hpp"

int main(){
    ConsoleIO io;
    Controller controller(io);
    controller.exec();
}