#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QObject>
#include "commandCreator.hpp"
#include <sstream>

class Controller: public QObject{
    Q_OBJECT
public:     
    void run(std::istream& input);
    void logOutput(const std::string& output);

signals:
    void outputLoged(const std::string& output);
 
private:
    CommandCreator creator;
};

#endif //CONTROLLER_HPP
