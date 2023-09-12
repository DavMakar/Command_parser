#ifndef ABSTRACT_COMMAND_HPP
#define ABSTRACT_COMMAND_HPP

#include <vector>

class Command{
    public:
        virtual double exec(const std::vector<double>& operands_ ) const = 0;
        virtual ~Command(){};
};

#endif //ABSTRACT_COMMAND_HPP
