#ifndef ABSTRACT_COMMAND_HPP
#define ABSTRACT_COMMAND_HPP

#include <vector>
#include <memory>

class Command{
    public:
        virtual double exec(const std::vector<double>& operands_ ) const = 0;
        virtual std::unique_ptr<Command> clone() const = 0;         
        virtual ~Command(){};
};

#endif //ABSTRACT_COMMAND_HPP
