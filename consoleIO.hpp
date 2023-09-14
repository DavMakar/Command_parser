#ifndef CONSOLE_IO_HPP
#define CONSOLE_IO_HPP

#include "ioInterface.hpp"
#include <vector>
#include <string>

using Token = std::string;
using TokenVector = std::vector<Token>;

class ConsoleIO : public IOInterface{
public:
    TokenVector getInput(std::string_view) override;
    void printOutput(std::string_view output) override;
};

#endif //CONSOLE_IO_HPP