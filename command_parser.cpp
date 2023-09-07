#include "command_parser.hpp"

CommandParser::ParserResult CommandParser::parse(std::stringstream& ss){
    ParserResult result;

    ss >> std::get<0>(result);

    while (!ss.eof())
    {
        std::string token;
        ss >> token;
        if(token == "-op1"){
            ss >> std::get<1>(result);
        }
        else if(token == "-op2"){
            ss >> std::get<2>(result);
        }
    }
    return result; 
}