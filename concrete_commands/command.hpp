#ifndef ABSTRACT_COMMAND_HPP
#define ABSTRACT_COMMAND_HPP

class Command{
    public:
        virtual double exec(const double ,const double) const = 0;
        virtual ~Command(){};
};

#endif //ABSTRACT_COMMAND_HPP
