#ifndef CONCRETE_COMMANDS_HPP
#define CONCRETE_COMMANDS_HPP

#include "command.hpp"

class AddCommand: public Command{
public:
    double exec(const double op1,const double op2)const  override{
        return op1 + op2;      
    }
};

class MulCommand: public Command{
public: 
    double exec(const double op1,const double op2)const override{
        return op1 * op2;      
    }
};

class DivCommand : public Command{
    double exec(const double op1,const double op2)const override{
        return op1 / op2;      
    }
};

class SubCommand : public Command{
    double exec(const double op1, const double op2)const override{
        return op1 - op2;
    }
};

#endif //CONCRETE_COMMANDS_HPP