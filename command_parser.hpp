#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <sstream>
#include <tuple>
#include <string>

class CommandParser{

    using ParserResult = std::tuple< std::string , double , double>;
    public:
        ParserResult parse(std::stringstream& ss);
};

#endif // COMMAND_PARSER_HPP