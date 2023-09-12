#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <sstream>
#include <vector>
#include <string>

class CommandParser{
    public:
        void tokenize(std::stringstream& ss);
        std::string get_operator();
        std::vector<double> get_operands();
    private:
        std::string operator_;
        std::vector<double> operands_; 
};

#endif // COMMAND_PARSER_HPP