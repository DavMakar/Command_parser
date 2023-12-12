#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "commandCreator.hpp"
#include <istream>

class Controller{
public:     
    void run(std::istream& input);
private:
    CommandCreator creator;
};

#endif //CONTROLLER_HPP
