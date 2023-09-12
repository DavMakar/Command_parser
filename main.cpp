#include "controller.hpp"
#include "consoleIO.hpp"

int main(){
    ConsoleIO io;
    Controller calc(io);
    calc.exec();
}