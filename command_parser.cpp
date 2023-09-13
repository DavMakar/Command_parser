#include "command_parser.hpp"

void CommandParser::parse(std::string token){
    ss >> operator_;

    while (!ss.eof())
    {
        std::string token;
        ss >> token;
        double operand;
        if(token.substr(0,3) == "-op"){
            ss >> operand;
            operands_.push_back(operand);
        }else{
            throw std::runtime_error("-opN , N = [1,2,....,n]");
        }
    }
    
    if(operator_!= "" && operands_.empty()){
        throw std::runtime_error("zero operands");
    }
}

std::string CommandParser::get_operator()
{
    return operator_;
}

std::vector<double> CommandParser::get_operands()
{
    std::vector<double> tmp;
    std::swap(tmp, operands_);
    return tmp;
}
