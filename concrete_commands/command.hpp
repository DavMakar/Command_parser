#ifndef ABSTRACT_COMMAND_HPP
#define ABSTRACT_COMMAND_HPP

#include <vector>
#include <memory>

class Command{
    public:
        virtual double exec() const = 0;
        virtual std::unique_ptr<Command> clone() const = 0;          
        virtual void addOperand(std::string key , std::string value){
            if(key.compare("-op")){
                throw std::runtime_error("write -op before value");    
            }
            operands_.push_back(std::stod(value));
        }         
        virtual ~Command(){};
    protected:
        std::vector<double> operands_;
};


#endif //ABSTRACT_COMMAND_HPP
