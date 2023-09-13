#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <sstream>
#include <vector>
#include <string>
#include "commandRegistry.hpp"

class CommandParser{
    public:
        void parse(std::string token);
        std::string get_operator();
        std::vector<double> get_operands();
    private:
        CommandRegistry register_;
        std::string operator_;
        std::vector<double> operands_; 
};

#endif // COMMAND_PARSER_HPP