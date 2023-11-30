#ifndef CONSOLE_IO_HPP
#define CONSOLE_IO_HPP

#include "ioInterface.hpp"

class ConsoleIO : public IOInterface{
public:
    std::istringstream getInput(std::string_view) override;
    void printOutput(std::string_view output) override;
};

#endif //CONSOLE_IO_HPP