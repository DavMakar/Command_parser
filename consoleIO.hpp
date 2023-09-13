#ifndef CONSOLE_IO_HPP
#define CONSOLE_IO_HPP

#include "ioInterface.hpp"
#include <vector>
#include <string>

using Token = std::string;
using TokenVector = std::vector<Token>;

class ConsoleIO : public IOInterface{
    public:
        TokenVector getInput() override;
        void printOutput(std::string_view output) override;
    private:
        void tokenizeInput();
        TokenVector inputTokens;
};

#endif //CONSOLE_IO_HPP