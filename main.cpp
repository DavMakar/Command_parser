#include "Application.hpp"
#include "consoleIO.hpp"

int main(){
    ConsoleIO io;
    Application app(io);
    app.exec();
}